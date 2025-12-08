#include <math.h>
#include <stdio.h>
#include "complex.h"
#include "testCommon.h"


// 複素数構造体を使う時には次の行を活かす
#include "complex.h"
#include "testCommon.h"

// 各自の場所に記載してください。順番が違ってもテストには問題ないので気にしないでください。

/* テスト関数の記述部 */
// ↓↓↓↓ 3327 中野光喜 記述部(この範囲以外には追加しない)

void testFirst() {
    testStart("first");
    assertEqualsInt(1 * 1, 1);
    assertEqualsInt(2 * 2, 4);
}
void testMakeCompRT() {
    complex  ans;
    testStart("makeCompRT");
    // 3∠0
    ans = makeCompRT(3.0, 0);
    assertEqualsComplex(ans, makeComp(3.0, 0));
    // 2∠π/2
    ans = makeCompRT(2.0, M_PI/2.0);
    assertEqualsComplex(ans, makeComp(0, 2.0));
    // 1∠(-π/4)
    ans = makeCompRT(1.0, -M_PI/4.0);
    assertEqualsComplex(ans, makeComp(1/sqrt(2), -1/sqrt(2)));
}





// ↑↑↑↑ ここまでを 3327 中野光喜 が記述(この範囲以外には追加しない)

//////////////////////////////////////////////////////////////////////////////////////////

// ↓↓↓↓ 3328 西口豪志 記述部(この範囲以外には追加しない)

void testSecond() {
    testStart("second");
    assertEqualsDouble(sqrt(4.0), 2.0);
    assertEqualsDouble(sqrt(9.0), 3.0);
}
void testMakeComp() {
    complex ans;
    testStart("makeComp");
    // 1+2jを作成
    ans = makeComp(1.0, 2.0);
    assertEqualsDouble(ans.real, 1.0);
    assertEqualsDouble(ans.image, 2.0);
    // 3.4+5.6jを作成
    ans = makeComp(3.4, 5.6);
    assertEqualsDouble(ans.real, 3.4);
    assertEqualsDouble(ans.image, 5.6);
}
void testAddComp() {
    complex a, b, ans;

    testStart("addComp");

    // ---- Test 1: (1 + 2j) + (3 + 4j) = (4 + 6j) ----
    a = makeComp(1.0, 2.0);
    b = makeComp(3.0, 4.0);
    ans = addComp(a, b);

    assertEqualsDouble(ans.real, 4.0);
    assertEqualsDouble(ans.image, 6.0);

    // ---- Test 2: (3.4 + 5.6j) + (1.1 + 2.2j) = (4.5 + 7.8j) ----
    a = makeComp(3.4, 5.6);
    b = makeComp(1.1, 2.2);
    ans = addComp(a, b);

    assertEqualsDouble(ans.real, 4.5);
    assertEqualsDouble(ans.image, 7.8);

    // ---- Test 3: (0 + 0j) + (2.5 + -3.1j) = (2.5 + -3.1j) ----
    a = makeComp(0.0, 0.0);
    b = makeComp(2.5, -3.1);
    ans = addComp(a, b);

    assertEqualsDouble(ans.real, 2.5);
    assertEqualsDouble(ans.image, -3.1);
}


// 8. 共役複素数 (虚部の符号が反転)
void testConjComp() {
    complex a, ans;
    testStart("conjComp");

    // 1+2j の共役 -> 1-2j
    a = makeComp(1.0, 2.0);
    ans = conjComp(a);
    assertEqualsDouble(ans.real, 1.0);
    assertEqualsDouble(ans.image, -2.0);

    // -3-4j の共役 -> -3+4j
    a = makeComp(-3.0, -4.0);
    ans = conjComp(a);
    assertEqualsDouble(ans.real, -3.0);
    assertEqualsDouble(ans.image, 4.0);
}

// 9. 逆数 (1/a)
void testInvComp() {
    complex a, ans;
    testStart("invComp");

    // 2+0j の逆数 -> 0.5+0j
    a = makeComp(2.0, 0.0);
    ans = invComp(a);
    assertEqualsDouble(ans.real, 0.5);
    assertEqualsDouble(ans.image, 0.0);

    // 1+1j の逆数 -> 1/(1+j) = (1-j)/2 = 0.5 - 0.5j
    a = makeComp(1.0, 1.0);
    ans = invComp(a);
    assertEqualsDouble(ans.real, 0.5);
    assertEqualsDouble(ans.image, -0.5);
}

// 10. 除算 (a/b)
void testDivComp() {
    complex a, b, ans;
    testStart("divComp");

    // (2+4j) / (2+0j) -> 1+2j
    a = makeComp(2.0, 4.0);
    b = makeComp(2.0, 0.0);
    ans = divComp(a, b);
    assertEqualsDouble(ans.real, 1.0);
    assertEqualsDouble(ans.image, 2.0);

    // (1+1j) / (1+1j) -> 1+0j
    a = makeComp(1.0, 1.0);
    b = makeComp(1.0, 1.0);
    ans = divComp(a, b);
    assertEqualsDouble(ans.real, 1.0);
    assertEqualsDouble(ans.image, 0.0);
}

// 11. 実部のみ出力 (getR)
void testGetR() {
    complex a;
    double ans;
    testStart("getR");

    // 3.4 + 5.6j -> 3.4
    a = makeComp(3.4, 5.6);
    ans = getR(a);
    assertEqualsDouble(ans, 3.4);
}

// 12. 偏角 (getTheta)
// 第一象限から第四象限まですべて網羅すること、という仕様に対応
void testGetTheta() {
    complex a;
    double ans;
    testStart("getTheta");

    // 第1象限 (1, 1) -> 45度 (PI/4)
    a = makeComp(1.0, 1.0);
    ans = getTheta(a);
    assertEqualsDouble(ans, M_PI / 4.0);

    // 第2象限 (-1, 1) -> 135度 (3*PI/4)
    a = makeComp(-1.0, 1.0);
    ans = getTheta(a);
    assertEqualsDouble(ans, 3.0 * M_PI / 4.0);

    // 第3象限 (-1, -1) -> -135度 (-3*PI/4) 
    // ※atan2の実装によりますが、通常 -PI < theta <= PI で返ります
    a = makeComp(-1.0, -1.0);
    ans = getTheta(a);
    assertEqualsDouble(ans, -3.0 * M_PI / 4.0);

    // 第4象限 (1, -1) -> -45度 (-PI/4)
    a = makeComp(1.0, -1.0);
    ans = getTheta(a);
    assertEqualsDouble(ans, -M_PI / 4.0);
}

// 13. a + bj 形式の表示 (printComp)
// 画面表示は自動テストできないので、目視確認用のログを出します
void testPrintComp() {
    complex a;
    testStart("printComp (Visual Check)");
    
    printf("Expected: 1.000+2.000j\n");
    printf("Result  : ");
    a = makeComp(1.0, 2.0);
    printComp(a);
    printf("\n");

    printf("Expected: 1.000-2.000j (虚部が負の時)\n");
    printf("Result  : ");
    a = makeComp(1.0, -2.0);
    printComp(a);
    printf("\n");
}

// 14. Re^{j\theta} 形式の表示 (printCompRT)
// ラジアンから度数法への変換を確認
void testPrintCompRT() {
    complex a;
    testStart("printCompRT (Visual Check)");

    // 1+1j -> √2 ∠ 45.000
    printf("Expected: 1.414/45.000\n"); // √2 ≒ 1.41421356
    printf("Result  : ");
    a = makeComp(1.0, 1.0);
    printCompRT(a);
    printf("\n");
}

// ↑↑↑↑ ここまでを 3328 西口豪志 が記述(この範囲以外には追加しない)

//////////////////////////////////////////////////////////////////////////////////////////



// ここから main の始まりまでは追加・変更しないでください。

/* main関数の記述部 */
int main() {
    // ↓↓↓↓ 33xx XXXX 記述部(この範囲以外には追加しない)
    testFirst();
    // ↑↑↑↑ ここまでを 33xx XXXX が記述(この範囲以外には追加しない)
    testMakeCompRT();
    testConjComp();     // No.8
    testInvComp();      // No.9
    testDivComp();      // No.10
    testGetR();         // No.11
    testGetTheta();     // No.12
    testPrintComp();    // No.13
    testPrintCompRT();  // No.14
    //////////////////////////////////////////////////////////////////////////////////////////

    // ↓↓↓↓ 33yy YYYY 記述部(この範囲以外には追加しない)
    testSecond(); 
    
    testMakeComp();

    // ↑↑↑↑ ここまでを 33yy YYYY が記述(この範囲以外には追加しない)

    //////////////////////////////////////////////////////////////////////////////////////////

 

    testErrorCheck();  // これは消さないこと
    return 0;
}
