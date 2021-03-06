# 接点バウンス / 接点チャタリング

<!---
  original document: 0.11.53:docs/feature_debounce_type.md
  git diff 0.11.53 HEAD -- docs/feature_debounce_type.md | cat
-->

メカニカルスイッチは押した状態と放した状態の間の移行が単純ではないことが良くあります。

理想的な世界では、スイッチを押すと、デジタルピンが次のようになることが期待されます:
(X 軸は時間を表します
```
voltage                   +----------------------
 ^                        |
 |                        |
 |      ------------------+
          ----> time
```

しかし実際の世界では、値が最終的に落ち着くまでに 0 と 1 の間を行ったり来たりする接点バウンスを見ることになるでしょう。（訳注：日本語では、バウンスとチャタリングを区別せずにチャタリングと呼んでいることが多いようです。）
```
                  +-+ +--+ +-------------
                  | | |  | |
                  | | |  | |
+-----------------+ +-+  +-+
```
スイッチが落ち着くまでにかかる時間は、スイッチの種類や経年、押す技術によって異なる場合があります。

デバイスが接点バウンスを緩和しないことを選択した場合、スイッチが押された時に起きるアクションが複数回繰り返されることがよくあります。

接点バウンス(「デバウンス」)を処理する方法はたくさんあります。RC フィルタのような追加のハードウェアを採用する方法もありますが、ソフトウェアでデバウンスを行う様々な方法もあり、よくデバウンスアルゴリズムと呼ばれます。このページでは、QMK で利用できるデバウンスメソッドについて説明します。

技術的には接点バウンス/接点チャタリングとは見なされませんが、一部のスイッチテクノロジーはノイズの影響を受けやすく、キーの状態が変化していない時に、時々短くランダムに 0 と 1 の間を行き来する様子がデジタル回路によって読み取られる場合があります。例えば:
```
                  +-+
                  | |
                  | |
+-----------------+ +--------------------
```

多くのデバウンスメソッド(全てではないですが)は、デバイスにノイズ耐性を持たせます。
ノイズの影響を受けやすい技術を使っている場合は、ノイズを緩和するデバウンスメソッドを選択しなければなりません。

## デバウンスアルゴリズムの種類

1) 時間の単位: タイムスタンプ (ミリ秒) vs 周期 (スキャン)
   * デバウンスアルゴリズムは1つの「デバウンス時間」パラメータを持つことがよくあり、スイッチ接点の最大セトリング時間を指定します。
     この時間は様々な単位で測定される場合があります:
     * 周期ベースデバウンスは n 周期(スキャン)待機し、matrix_scan ごとにカウントを1減らします。
     * タイムスタンプベースのデバウンスは、変更が発生したミリ秒のタイムスタンプを格納し、経過時間を計算するために減算を行います。
   * 通常、タイムスタンプベースのデバウンスは、特にノイズ耐性のあるデバイスで優れています。なぜなら、物理スイッチのセトリング時間は時間の単位で指定されており、キーボードのマトリックススキャンレートに依存しないからです。
   * 周期ベースのデバウンスは、補正できるセトリング時間がマトリックススキャンコードのパフォーマンスに依存するため、劣ると見なされる場合があります。
     周期ベースのデバウンスを使う場合、スキャンコードのパフォーマンスを大幅に向上させると、デバウンスの効果が低下する場合があります。
     周期ベースのデバウンスが望ましい状況は、ノイズが存在し、スキャンアルゴリズムが遅い、もしくは速度が可変である場合です。
     デバウンスアルゴリズムが基本的にノイズ耐性がある場合でも、スキャンが遅く、タイムスタンプベースのアルゴリズムを使っている場合は、
     2つのサンプル値に基づいてデバウンスを決定するため、アルゴリズムのノイズ耐性は制限されます。
   * 現在、全ての組み込みデバウンスアルゴリズムは、タイムスタンプベースのデバウンスのみサポートしています。将来的には周期ベースのデバウンスを実装し、```config.h``` マクロを介して選択できるようになるでしょう。

2) 対称 vs 非対称
   * 対称 - キーアップとキーダウンイベントの両方に、同じデバウンスアルゴリズムを適用します。
     * 推奨される命名規則: ```sym_*```
   * 非対称 - キーダウンとキーアップイベントに異なるデバウンスアルゴリズムを適用します。例えば、キーダウンはイーガー、キーアップはデファー。
     * 推奨される命名規則: ```asym_*``` の後に、キーダウン、キーアップの順に使っているアルゴリズムタイプの詳細が続きます。

3) イーガー vs デファー
   * イーガー - キーの変更はすぐに報告されます。DEBOUNCE ミリ秒以降の全ての入力は無視されます。
     * イーガーアルゴリズムはノイズ耐性はありません
     * 推奨される命名規則:
        * ```sym_eager_*```
        * ```asym_eager_*_*```: キーダウンはイーガーアルゴリズムを使います
        * ```asym_*_eager_*```: キーアップはイーガーアルゴリズムを使います
   * デファー - 変更を報告する前に DEBOUNCE ミリ秒の間変更がないことを待機します
     * デファーアルゴリズムはノイズ耐性があります
     * 推奨される命名規則:
        * ```sym_defer_*```
        * ```asym_defer_*_*```: キーダウンはデファーアルゴリズムを使います
        * ```asym_*_defer_*```: キーアップはデファーアルゴリズムを使います

4) グローバル vs キーごと vs 行ごと
   * グローバル - 全てのキーに対して1つのタイマー。キーの変更状態は、グローバルタイマーに影響を与えます。
     * 推奨される命名規則: ```*_g```
   * キーごと - キーごとに1つのタイマー。
     * 推奨される命名規則: ```*_pk```
   * 行ごと - 行ごとに1つのタイマー。
     * 推奨される命名規則: ```*_pr```
   * キーごとや行ごとのアルゴリズムはより多くのリソース(パフォーマンスと RAM 使用量の観点で)を消費しますが、高速なタイピストはグローバルよりもそれらを好む場合があります。

## QMK でサポートされるデバウンスアルゴリズム

QMK はデバウンス API を介して複数のデバウンスアルゴリズムをサポートします。

### デバウンスの選択

| DEBOUNCE_TYPE | 説明                                                          | 他に必要なもの                                                               |
| ------------- | ------------------------------------------------------------- | ---------------------------------------------------------------------------- |
| 未定義        | デフォルトのアルゴリズム、現在のところ sym_defer_g を使います | 無し                                                                         |
| custom        | 独自のデバウンスコードを使います                              | ```SRC += debounce.c``` で独自の debounce.c を追加し、必要な関数を実装します |
| その他        | quantum/debounce/* から他のアルゴリズムを使います             | 無し                                                                         |

**分割キーボードについて**:
デバウンスコードは分割キーボードと互換性があります。

### インクルードされているデバウンスメソッドの選択
キーボードは、```rules.mk``` に次の行を追加することで、既に実装されているデバウンスメソッドの1つを選択できます:
```
DEBOUNCE_TYPE = <アルゴリズムの名前>
```
アルゴリズムの名前は次のいずれかです:
* ```sym_defer_g``` - キーボードごとにデバウンスします。状態が変化すると、グローバルタイマが設定されます。```DEBOUNCE``` ミリ秒の間何も変化がなければ、全ての入力の変更がプッシュされます。
  * これは現在のデフォルトアルゴリズムです。これはメモリ使用量が最も少ない最高のパフォーマンスのアルゴリズムで、ノイズ耐性もあります。
* ```sym_eager_pr``` - 行ごとにデバウンスします。状態が変化すると、応答は即座に行われ、その後その行は ```DEBOUNCE``` ミリ秒の間入力されません。
```NUM_KEYS``` の 8ビットカウンタの更新に高い計算コストがかかる、もしくは低スキャンレートのキーボード用で、各指は通常一度に1行しか叩かないようになっています。これは ErgoDox モデルに適しています; マトリックスは90度回転しているため、その「行」は実際には「列」であり、通常の使用では各指は一度に1つの「行」にしか当たりません。
* ```sym_eager_pk``` - キーごとにデバウンスします。状態が変化すると、応答は即座に行われ、その後そのキーは ```DEBOUNCE``` ミリ秒の間入力されません。
* ```sym_defer_pk``` - キーごとにデバウンスします。状態が変化すると、キーごとのタイマーが設定されます。```DEBOUNCE``` ミリ秒の間そのキーに変化がなければ、キーの状態の変更がプッシュされます。

### 将来実装される可能性のあるいくつかのアルゴリズム:
* ```sym_defer_pr```
* ```sym_eager_g```
* ```asym_eager_defer_pk```

### 独自のデバウンスコードの使用
独自のデバウンスアルゴリズムを実装するためのオプションがあります。次のようにします:
* ```rules.mk``` に ```DEBOUNCE_TYPE = custom``` を設定します。
* ```rules.mk``` に ```SRC += debounce.c``` を追加します。
* 独自の ```debounce.c``` を追加します。例については、```quantum/debounce``` にある現在の実装を見てください。
* デバウンスは、全てのマトリクススキャンの後で発生します。
* MATRIX_ROWS ではなく num_rows を使って、分割キーボードが正しくサポートされるようにします。
* アルゴリズムが他のキーボードにも適用できる可能性がある場合、```quantum/debounce``` に追加することを検討してください。
