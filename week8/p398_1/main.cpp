#include "Sample.h"

int main() {
    Sample a("sample");
    a.printCount();

    Sample b(a); // 복사 생성자 호출
    b.printCount();

    return 0;
}
