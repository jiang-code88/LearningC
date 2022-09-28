- 在 C 语言出现之前，UNIX 操作系统的初级版本是用汇编语言编写的。用机器语言或者汇编语言开发的程序，是不可能在诸如 X86、Alpha、SPARC、PPC 和 ARM 等机器上任意运行的。
- 用 C 语言编写的程序，则可以在任意架构的处理器上运行。只需要有那种架构的处理器对应的 C 语言编译器和库，然后将 C 源代码编译、链接成目标二进制文件，之后即可在该架构的处理器上运行。

### C语言的语言特征

1. 简单的类型系统和静态编译，方便预知程序的运行流程和结果。
2. C语言能灵活的操控内存和寄存器，方便C语言用于开发底层核心代码。
   - 能完全的操作计算机的所有资源。
3. 提供结构体、函数等抽象的编程机制，方便C语言的可移植性。

- C语言有函数、变量（局部变量、全局变量）、变量类型（用于存储各种类型的数据）、指针（特殊的变量）、指针的类型（用于存放其他变量的地址）。
- C语言就是函数+变量。函数表示算法操作，变量存放数据。（程序=算法+数据结构）

```c
#include "stdio.h"
// 定义申明两个全局变量：hellostr、global，类型分别是：char*、int；
char* hellostr = "HelloWorld";
int global = 5;
// 定义一个结构体类型 HW；
struct HW {
  char* str;
  int sum;
  long indx;
};
// 函数；
void show(struct HW* hw, long x) {
  printf("%d %d %s\n", global, x, hellostr);
  printf("%d %d %s\n", hw->sum, hw->indx, hw->str);
}
// 函数；
int main(int argc, char const *argv[]) {
  // 定义三个局部变量：x、parm、ishw，类型分别是：int、log、struct HW;
  int x;
  long parm = 10;
  struct HW ishw;
  // 变量赋值;
  ishw.str = hellostr;
  ishw.sum = global;
  ishw.indx = parm;
  // 调用函数;
  show(&ishw, parm);
  return x;
}
```

### C语言的本质

- C 语言的代码不能直接执行，需要通过 C 编译器编译。
- C 编译器首先将 C 代码编译成汇编代码，然后再通过汇编器编译成二进制机器代码，被机器直接执行。
- 汇编代码和机器指令直接对应的，不同的机器平台有不同的机器指令和汇编代码的对应关系。

### C语言指针变量带来的陷阱

C 语言的指针变量中存放的是地址数据，导致 C 语言程序员可以毫无节制地操控内存，这个特性赋予了 C 语言强大、灵活的特点，同时也带来了陷阱。

#### 陷阱一：未初始化的指针

- 未初始化的C语言指针变量 p ，会导致变量 i 的值无法控制，可能大于100也可能小于100，程序的运行结果完全无法控制。

```c
int main(int argc, char const *argv[]) {
  int* p;
  int k = *p;
  for (int i = k; i > 100; i++) {
    printf("hello world\n");
  }
  return 0;
}
```

#### 陷阱二：指针越界

- 已有的字符串数组 helloworld有10个字符，而我们的需要放入字符的字符数组是str[]，只能容纳5个字符。这样在不断往str数组中塞入字符时，肯定会跃出字符数组的内存空间范围，放入字符，造成数据写入破坏bug。

```c
char str[5] = { 0 };
void stringcopy(char* dest, char* src) {
  for(; *src != 0; dest++, src++) {
    *dest = *src;
  }
  return;
}
int main(int argc, char const *argv[]) {
  stringcopy(str, "helloworld");
  return 0;
}
```

#### 陷阱三：栈破坏

- 变量x的内存地址是在main函数的调用栈中分配内存空间的，这个内存空间就是栈中的一个内存地址。在stackret函数中，不断从变量x的地址上开始改写，将main函数的调用栈中的函数返回地址改写成，调用test方法的地址。

```c
void test() {
  printf("test");
  return;
}
void stackret(long* l) {
 *l-- = (long)test;
 *l-- = (long)test;
 *l-- = (long)test;
 *l-- = (long)test;
 *l-- = (long)test;
  return;
}
int main(void) {
  int* p;
  long x = 0;
  stackret(&x);
  return 0;
}
```

### C语言中对于面向过程和面向对象两种思想

- 从汇编到 C 再到 C++、 Java，都是命令式语言。也就是围绕着存储和处理两大核心，存储被抽象为内存，处理被抽象为运算指令和语句。目的在于通过运算去改变内存（存储的数据）。

- 面向对象是面向过程的衍生。
- 过程是对每个功能或者动作的精细实现。对象是针对不同的对象都有的这个动作进行封装和实现，对象自己调用自己的方法，完成相应的吃饭动作。
- 封装的目的是为了继承，没有了继承封装对象将失去意义。继承的目的是为了解耦和复用。单 / 多继承又会带来额外的复杂度，于是出现组合优于继承的思想。

### 参考

- [大咖助阵｜LMOS：为什么说 C 语言是一把瑞士军刀？](https://time.geekbang.org/column/article/474870)
- [大咖助阵｜LMOS：用面向对象的思想开发 C 语言程序](https://time.geekbang.org/column/article/470130)