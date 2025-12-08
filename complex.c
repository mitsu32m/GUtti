// X班 complex.c

#include "complex.h"

#include <math.h>
#include <stdio.h>

// テスト作成者は雛形までを作成し、コンパイルができるまでを責任とします。
// コンパイルができたところで、コミットしてください。


//↓↓↓↓ 3328 西口豪志 記述部(雛形まで。この範囲以外には追加しない)

complex makeComp(double real, double image) {
    complex ans;
    ans.real = real ;
    ans.image = image;
    return ans;
}

complex addComp(complex a, complex b){
     return makeComp( a.real +b.real , a.image + b.image);
}


//↑↑↑↑ ここまでを 3328 西口豪志 が記述(この範囲以外には追加しない)

//↓↓↓↓ 3327 中野光喜 記述部(雛形まで。この範囲以外には追加しない)
complex makeCompRT(double r, double theta){
    return makeComp( r * cos(theta), r * sin(theta));
}
// 8. 共役複素数 a* (虚部の符号が異なる複素数): conjComp [cite: 81]
complex conjComp(complex a) {
    // 虚部の符号を反転させて新しい複素数を作る
    return makeComp(a.real, -a.image);
}

// 7. (補足) 大きさの二乗 |a|^2: getR2 [cite: 75]
// ※9.の逆数計算で使うため、もし未実装ならここに追加してください
double getR2(complex a) {
    return (a.real * a.real) + (a.image * a.image);
}

// 9. 逆数 1/a: invComp [cite: 90]
// 公式: (a - jb) / (a^2 + b^2) 
complex invComp(complex a) {
    double norm_sq = getR2(a); // 大きさの二乗を取得
    
    // 0割りなどのエラー処理は仕様にないため省略していますが、
    // 実際には norm_sq != 0 の確認が必要です。
    
    // 実部: a / (a^2 + b^2)
    // 虚部: -b / (a^2 + b^2)
    return makeComp(a.real / norm_sq, -a.image / norm_sq);
}

// 10. 除算 a/b: divComp [cite: 101]
// 公式: a * (1/b) 
complex divComp(complex a, complex b) {
    complex invB = invComp(b); // bの逆数を求める
    
    // 複素数の掛け算を行う: a * invB
    // (ac - bd) + j(ad + bc)
    // ここでは mulComp (No.6) があると仮定して呼び出すか、
    // 以下のように直接計算式を書きます。
    
    double real_part = (a.real * invB.real) - (a.image * invB.image);
    double image_part = (a.real * invB.image) + (a.image * invB.real);
    
    return makeComp(real_part, image_part);
}

// 11. Rのみの出力 (大きさ): getR [cite: 111]
double getR(complex a) {
    // 平方根をとって大きさを求める
    return sqrt(getR2(a));
}

// 12. thetaのみの出力 (偏角・ラジアン): getTheta [cite: 121]
// 第1～第4象限すべてに対応するため atan2 を使用
double getTheta(complex a) {
    return atan2(a.image, a.real);
}

// 13. a + bj の形の表示: printComp [cite: 127]
// 例: 1.000+2.000j
void printComp(complex a) {
    // %+.3f とすることで、正の数にも自動で + がつき、負なら - がつきます
    printf("%.3f%+.3fj\n", a.real, a.image);
}

// 14. Re^{j\theta} の形の表示: printCompRT [cite: 136]
// 例: 1.000/45.000 (仕様書の例に合わせ、区切り文字は / としています)
// 内部はラジアンですが、表示は「度」に変換します 
void printCompRT(complex a) {
    double r = getR(a);
    double theta_rad = getTheta(a);
    
    // ラジアンを度に変換 (rad * 180 / PI)
    double theta_deg = theta_rad * 180.0 / M_PI;
    
    printf("%.3f/%.3f\n", r, theta_deg);
}
//↑↑↑↑ ここまでを 33xx XXXX が記述(この範囲以外には追加しない)

//////////////////////////////////////////////////////////////////////////////////////////


// ここから下には何も追記しないでください。