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


// ↑↑↑↑ ここまでを 3328 西口豪志 が記述(この範囲以外には追加しない)

//////////////////////////////////////////////////////////////////////////////////////////



// ここから main の始まりまでは追加・変更しないでください。

/* main関数の記述部 */
int main() {
    // ↓↓↓↓ 33xx XXXX 記述部(この範囲以外には追加しない)
    testFirst();
    // ↑↑↑↑ ここまでを 33xx XXXX が記述(この範囲以外には追加しない)
    testMakeCompRT();
    //////////////////////////////////////////////////////////////////////////////////////////

    // ↓↓↓↓ 33yy YYYY 記述部(この範囲以外には追加しない)
    testSecond(); 
    
    testMakeComp();

    // ↑↑↑↑ ここまでを 33yy YYYY が記述(この範囲以外には追加しない)

    //////////////////////////////////////////////////////////////////////////////////////////

 

    testErrorCheck();  // これは消さないこと
    return 0;
}
