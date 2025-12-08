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

// ↑↑↑↑ ここまでを 3328 西口豪志 が記述(この範囲以外には追加しない)

//////////////////////////////////////////////////////////////////////////////////////////



// ここから main の始まりまでは追加・変更しないでください。

/* main関数の記述部 */
int main() {
    // ↓↓↓↓ 33xx XXXX 記述部(この範囲以外には追加しない)
    testFirst();
    // ↑↑↑↑ ここまでを 33xx XXXX が記述(この範囲以外には追加しない)

    //////////////////////////////////////////////////////////////////////////////////////////

    // ↓↓↓↓ 33yy YYYY 記述部(この範囲以外には追加しない)
    testSecond(); 
    
    testMakeComp();

    // ↑↑↑↑ ここまでを 33yy YYYY が記述(この範囲以外には追加しない)

    //////////////////////////////////////////////////////////////////////////////////////////

 

    testErrorCheck();  // これは消さないこと
    return 0;
}
