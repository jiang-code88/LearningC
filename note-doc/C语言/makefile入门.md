## makefile

源文件Source File(.c) ---编译(compile)---> 中间代码文件 Object File (.o) ---链接(link)--->可执行文件。

- 编译：检测程序语法正确，函数与变量声明正确。
- 链接：告诉编译器头文件所在位置。（从 Object File 中找寻函数的实现）
- 库文件（Libaray File / Archive File / .a）：把中间代码文件打包的文件，便于链接使用。

### makefile 编写规则：

```makefile
target ... : prerequisites ...
    command
    ...
    ...
```

- target：目标文件（object file）/ 可执行文件 / 标签（label）
- prerequisites：生成该 target 所依赖的文件（c 文件或头文件）/ target 
- command：生成该 target 要执行的命令（任意的 shell 命令）

> makefile 的规则：
>
> - target 这一个或多个目标或可执行文件依赖于 prerequisites 中的文件，通过 prerequisites 生成 target 的规则定义在 command 中。
> - prerequisites 中如果有一个或以上的文件比 target 中的文件要新，或者 target 不存在的话，command 所定义的命令就会被执行。

### make 命令编译和链接文件的规则：

1. 当这个工程没有编译过，那么所有的 c 文件都要编译并被链接。
2. 如果这个工程某几个 c 文件被修改，那么只编译被修改的 c 文件，并链接目标程序。
3. 如果这个工程某几个头文件被改变了，那么将编译引用了这几个头文件的 c 文件，并链接目标程序。

### make 命令运行规则的流程：

在默认的方式下，也就是我们只输入 `make` 命令。然后，

1. make会在当前目录下找名字叫“Makefile”或“makefile”的文件。
2. 如果找到，它会找文件中的第一个目标文件（target），并把这个文件作为最终的目标文件。
3. 如果目标文件不存在，或是目标文件所依赖的后面的 `.o` 文件的文件修改时间要比目标文件新，那么，他就会执行后面所定义的命令来生成 目标文件。
4. 如果目标文件所依赖的 `.o` 文件也不存在，那么make会在当前文件中找目标为 `.o` 文件的依赖性，如果找到则再根据那一个规则生成 `.o` 文件。（这有点像一个堆栈的过程）
5. 当然，你的C文件和H文件是存在的啦，于是make会生成 `.o` 文件，然后再用 `.o` 文件生成 make 的最终目标文件。

## quick start 

- 一个有3个头文件和8个c文件的工程。

```makefile
edit : main.o kbd.o command.o display.o \
        insert.o search.o files.o utils.o
    cc -o edit main.o kbd.o command.o display.o \
        insert.o search.o files.o utils.o

main.o : main.c defs.h
    cc -c main.c
kbd.o : kbd.c defs.h command.h
    cc -c kbd.c
command.o : command.c defs.h command.h
    cc -c command.c
display.o : display.c defs.h buffer.h
    cc -c display.c
insert.o : insert.c defs.h buffer.h
    cc -c insert.c
search.o : search.c defs.h buffer.h
    cc -c search.c
files.o : files.c defs.h buffer.h command.h
    cc -c files.c
utils.o : utils.c defs.h
    cc -c utils.c
# clean 没有被第一个目标文件间接或直接的关联，所以 clean 后面定义的命令不会被自动执行。
# 通过 make clean 显式的执行 clean 后定义的命令。
clean :
    rm edit main.o kbd.o command.o display.o \
        insert.o search.o files.o utils.o
```

- 注释使用 `#` ，换行符使用 `\` ，特殊字符使用 `\` 转义 。
- command 一定要使用 tab 键作为开头。
- `make` 命令可以自动识别当前目录下的 makefile 或 Makefile 的文件，输入 `make` 将生成可执行文件 edit，如果要删除目标文件和所有中间文件，执行 `make clean` 即可。
- clean 是一个动作标签，定义为冒号后面什么都没有。当我们要执行这个标签定义的 command 时，就要在 make 命令后明显的指出这个 label 的名字执行。常用于定义不用编译或是和编译无关的命令。

## 变量

- 相当于 C 语言的宏定义。

### 定义：

```makefile
objects = main.o kbd.o command.o display.o \
     insert.o search.o files.o utils.o
```

### 使用：

```makefile
$(objects)
```

## 清空目标文件的规则

```makefile
# 定义伪目标 clean 
.PHONY : clean

# 伪目标 clean 不要放文件的开头，放在文件的最后。
clean :
	# -rm ：表示执行命令出现错误时不管，继续做后面的事。
    -rm edit $(objects)
```

## 隐晦规则

- 当你不写出生成某个目标文件的规则而直接使用这个目标文件时，make 将试图去自动推导生成这个目标的规则和命令，这个行为就是隐含规则的自动推导。

```makefile
foo : foo.o bar.o
    cc –o foo foo.o bar.o $(CFLAGS) $(LDFLAGS)
```

- make 使用某个隐含规则：自动把 `.o` 的目标文件的依赖文件置成 `.c` ，并使用 C 的编译命令 `cc -c $(CFLAGE) foo.c` 来生成依赖文件 `foo.c` 的目标文件 `foo.o` 。

自动推导，使用隐含规则帮我们省略编写以下两条规则

```makefile
foo.o : foo.c
    cc –c foo.c $(CFLAGS)
bar.o : bar.c
    cc –c bar.c $(CFLAGS)
```

### 隐含规则使用的变量

- make 制定隐含规则时，会使用一些系统变量的值来制定，我们可以通过改变这些系统变量的值，定制生成的隐含规则。
- 第一条隐含规则——编译C程序的隐含规则的命令是 `$(CC) –c $(CFLAGS) $(CPPFLAGS)` 。Make默认的编译命令是 `cc` ，如果你把变量 `$(CC)` 重定义成 `gcc` ，把变量 `$(CFLAGS)` 重定义成 `-g` ，那么，隐含规则中的命令全部会以 `gcc –c -g $(CPPFLAGS)` 的样子来执行了。

#### 命令相关的

1. `CC` : C语言编译程序。默认命令是 `cc`
2. `AR` : 函数库打包程序。默认命令是 `ar`
3. `CXX` : C++语言编译程序。默认命令是 `g++`

#### 参数相关的

1. `CFLAGS` : C语言编译器参数。
2. `CXXFLAGS` : C++语言编译器参数。
3. `CPPFLAGS` : C预处理器参数。（ C 和 Fortran 编译器也会用到）。

### 模式规则

- 使用模式规则来定义一个自己的隐含规则。
- 一个模式规则就好像一个一般的规则，只是在规则中，目标文件的定义需要有 `%` 字符。 `%` 的意思是表示一个或多个任意字符（非空字符串）。在依赖文件中同样可以使用 `%` ，只是依赖文件中的 `%` 的取值，取决于其目标文件。

```makefile
%.o : %.c ; <command ......>;

或

%.o : %.c 
	<command ......>
		
# 从所有的 .c 文件生成相应的 .o 文件的规则, command 是要执行的命令。

%.o : %.c
    $(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@
# $@ 表示所有的目标文件的挨个值， $< 表示了所有依赖文件的挨个值。
```

### 自动化变量

1. `$@` : 表示规则中的目标文件集。

2. `$<` : 依赖文件集中的第一个目标名字，如果依赖文件是以模式（即 `%` ）定义的，那么 `$<` 将是符合模式的一系列的文件集。

3. `$?` : 所有比目标文件新的依赖文件的集合。以空格分隔。

   - ```makefile
     # 只对更新过的 object 文件进行打包。
     lib : foo.o bar.o lose.o win.o
         ar r lib $?
     ```

4. `$^` : 所有的依赖文件的集合。以空格分隔。取出重复的依赖目标。

5. `$+` : 所有依赖文件的集合。不去除重复的依赖目标。

> 四个变量（ `$@` 、 `$<` 、 `$%` 、 `$*` ）在扩展时只会是其中的逐个逐个文件，而另三个（`$?`、`$^`、`$+`）的值是一个文件列表。

## 伪目标

- 定义的 target 只是一个标签，不会被当做要生成的文件。

1. label 可定义依赖文件和命令，label 肯定是一个不存在的文件，所以肯定会执行 label 的命令。
2. 执行 label 命令的过程中，如果依赖文件不存在，将去到生成该依赖文件的规则中，判断是否执行命令生成。
3. 如果依赖文件存在（为空），直接执行 label 命令，且 label 不会被生成，所以也不会触发依赖文件比它新而执行 label 命令。

## 引用其他 Makefile 

- `include <filename>`

## 文件名通配符

`*`：`*.c` 表示所有后缀为c的文件

`?`：

`~`：当前用户的 `$HOME` 目录

## 依赖文件和目标文件找寻路径

- 首先在当前目录中找寻依赖和目标文件，找不到将到特殊变量 VPATH 中找寻文件。

  ```makefile
  VPATH = src:../headers
  ```

  - 定义了两个目录 src 和 ../headers，make会按照这个顺序进行搜索。目录由“冒号”分隔。

- .h 结尾的文件先在 foo 里面找，再到 bar 里面找，最后到 blish 里面找。

- vpath ：可以指定不同的文件在不同的搜索目录中

  ```makefile
  vpath %.h foo:bar
  vpath %   blish
  
  # vpath <pattern> <directories>
  # 为符合模式<pattern>的文件指定搜索目录<directories>。
  ```

> `<pattern>需要包含 % 字符，%` 的意思是匹配零或若干字符，`%.h` 表示所有以 `.h` 结尾的文件。

## 静态模式

- 静态模式可以更加容易地定义多目标的规则。

```makefile
<targets ...> : <target-pattern> : <prereq-patterns ...>
    <commands>
    ...
```

- targets 定义了一系列的目标文件，可以有通配符。是目标文件的一个集合。
- target-pattern 是指明了 targets 的模式，也就是从 \<taregets> 目标文件集合中抽取符合模式的目标文件组成集合，的目标文件模式。
- prereq-patterns 是目标文件的依赖文件模式，它对 target-pattern 形成的模式再进行一次依赖文件的定义。

```makefile
objects = foo.o bar.o

all: $(objects)

$(objects): %.o: %.c
    $(CC) -c $(CFLAGS) $< -o $@
# 原始的目标文件集合是 $object 变量定义的目标文件集合。
# %.o 表示获取其中所有以 .o 结尾的目标文件，组成模式目标文件集合。
# %.c 表示将上面获取的目标文件集合去除 .o 后缀，加上 .c 后缀，组成依赖文件集合。
# 取每一个依赖文件集合的依赖文件，执行命令生成对应的每一个目标文件。

# 以上命令简化了以下命令的编写
foo.o : foo.c
    $(CC) -c $(CFLAGS) foo.c -o foo.o
bar.o : bar.c
    $(CC) -c $(CFLAGS) bar.c -o bar.o
```



## 自动生成依赖性

- 自动找寻源文件中包含的头文件，并生成一个依赖关系。

## 命令

### 书写命令

- make 执行命令前会把命令输出在控制台。

  ```shell
  @命令：不输出命令在控制台
  ```

- `-n`：不执行命令，只输出，可用于调试查看 make 执行命令的顺序。

- -s：全面禁止命令的显示。

### 命令执行和出错

- 顺序关联执行的命令请使用 `;` 而不是换行进行分隔。
- 如果某个命令执行出错，将终止执行当前规则，且将有可能终止所有规则的执行。

- 命令前加 `-` 表示当命令执行出错时，忽略它，继续向下执行。

### 定义命令包

```makefile
define 命令包名
<command>
...
endef

define run-yacc
yacc $(firstword $^)
mv y.tab.c $@
endef

# 对 foo.c 执行 yacc 程序，将程序生成的 y.tab.c 文件重命名为 foo.y
foo.c : foo.y
    $(run-yacc)
```

## 条件判断

```makefile
<conditional-directive> # 指令
<text-if-true>  # 指令
else
<text-if-false> # 指令
endif


libs_for_gcc = -lgnu
normal_libs =

foo: $(objects)
ifeq ($(CC),gcc) # 判断$(CC)变量的值是否为 gcc ，然后决定是否指定 gnu 函数编译。
    $(CC) -o foo $(objects) $(libs_for_gcc)
else
    $(CC) -o foo $(objects) $(normal_libs)
endif
```

`<conditional-directive>`

- `ifeq(<arg1>,<arg2>)`：参数 `<arg1>` 是否等于 `<arg2>` ，相等为 true，否则为 false。

  - 同等写法：

    ```makefile
    ifeq (<arg1>, <arg2>)
    ifeq '<arg1>' '<arg2>'
    ifeq "<arg1>" "<arg2>"
    ifeq "<arg1>" '<arg2>'
    ifeq '<arg1>' "<arg2>"
    ```

- `ifnep`：ifeq 的反面。

  - 同等写法：

    ```makefile
    ifneq (<arg1>, <arg2>)
    ifneq '<arg1>' '<arg2>'
    ifneq "<arg1>" "<arg2>"
    ifneq "<arg1>" '<arg2>'
    ifneq '<arg1>' "<arg2>"
    ```

- `ifdef <variable-name>`：变量 `<variable-name>` 的值为空，则为 true ，否则为 false。

  - `<variable-name>` 还可以是函数的返回值。

- `ifndef`：ifdef 的反面。

## 函数

- 使用函数来处理变量，从而让我们的命令或是规则更加灵活和智能。

```makefile
# 调用函数
$(<function> <arguments>)

或

${<function> <arguments>}

# <function>: 函数名
# <arguments>: 参数名
```

- 函数名和参数之间用空格隔开，参数之间使用 `,` 分隔。

字符串处理函数

文件名处理函数

foreach 函数

```makefile
$(foreach <var>,<list>,<text>)
```

- 把 `<list>` 中的单词（以空格间隔）逐个取出放到变量 `<var>` 中，然后执行 `<text>` 所指定的表达式。
- 每执行一次 `<text>` 将返回一个字符串，循环结束后，将把每一个返回的字符串以空格分隔，组合成一个字符串作为 foreach 函数的返回值。

if 函数

```
$(if <condition>,<then-part>) # 如果 then-park 没有被执行，函数将返回空字符串。

$(if <condition>,<then-part>,<else-part>)

# <condition> 返回为非空字符串，为 true。空字符串，为 false。
```

call 函数

origin 函数

shell 函数

```makefile
contents := $(shell cat foo) # 执行 cat foo
files := $(shell echo *.c)# 执行 echo *.c
```

控制 make 函数

```makefile
$(error <text ...>)  # 产生 <text ...> 的错误信息
$(warning <text ...>) # 输出一段警告信息，而make继续执行
```









> - 感性的认识：感官的认识，长什么样子，是个什么形状、形式，放在那里在哪里出现。是初级阶段的认识。
>
> - 理性的认知：高级阶段的认识，对事物的内含，原理，进行归纳总结整理的思考认识，是自发的一种认识。
>
> 参考文档：
>
> 1. [跟我一起写Makefile](https://seisman.github.io/how-to-write-makefile/index.html)

