#ifndef __COMPLEX_H__
#define __COMPLEX_H__

// 二重読み込みを防ぐために、complex 構造体の定義などはここに記述




//////////////////////////////////////////////////////////////////////////////////////////

// プロトタイプ宣言部
//↓↓↓↓ 3327 中野光喜 記述部(この範囲以外に追加しない)
#ifndef COMPLEX_H
#define COMPLEX_H

/* 構造体の定義 */
// 実部(real)と虚部(image)をdouble型で持つ [cite: 27, 286]
typedef struct {
    double real;
    double image;
} complex;

/* プロトタイプ宣言 */



// 8. 共役複素数 a* (虚部の符号が異なる複素数) [cite: 113-118]
complex conjComp(complex a);

// 9. 逆数 1/a [cite: 124-128]
complex invComp(complex a);

// 10. 除算 a/b [cite: 140-146]
complex divComp(complex a, complex b);

// 11. R (大きさ) のみの出力 [cite: 157-161]
double getR(complex a);

// 12. θ (偏角) のみの出力 (ラジアンを返す) [cite: 167-172]
double getTheta(complex a);

// 13. a + bj の形の表示 (表示のみを行うため戻り値はvoidとしました) [cite: 178-182]
void printComp(complex a);

// 14. R∠θ の形の表示 (表示のみを行う、表示時は度数法に変換) [cite: 188-192, 198]
void printCompRT(complex a);

#endif // COMPLEX_H


//↑↑↑↑ ここまでを 3327 中野光喜 が記述(この範囲以外に追加しない)

//////////////////////////////////////////////////////////////////////////////////////////

//↓↓↓↓ 3328 西口豪志 記述部(この範囲以外に追加しない)

// 2. R∠θ (極座標形式) の形の代入 [cite: 45-51]
// ※図では第一引数の変数名が省略されていますが、仕様よりR(大きさ)と推測されます

complex makeComp(double real, double image);

complex makeCompRT(double r, double theta);

// 3. 加算 a + b [cite: 57-62]
complex addComp(complex a, complex b);

// 4. 減算 a - b [cite: 68-74]
complex subComp(complex a, complex b);

// 5. 定数倍 ka (kは実数) [cite: 80-86]
complex cmulComp(complex a, double k);

// 6. 乗算 ab [cite: 92-97]
complex mulComp(complex a, complex b);

// 7. R^2 (大きさの二乗) の出力 |a|^2 [cite: 103-107]
double getR2(complex a);

//↑↑↑↑ ここまでを 3328 西口豪志 が記述(この範囲以外に追加しない)



// ここから下には何も追記しないでください。

#endif