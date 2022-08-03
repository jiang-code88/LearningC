/*
** 1.程序功能介绍的注释文本
** This program reads input lines from the standard input and prints
** each input line, followed by just some portions of the lines, to
** the standard output.
**
** The first input is a list of column numbers, which ends with a
** negative number.  The column numbers are paired and specify
** ranges of columns from the input line that are to be printed.
** For example, 0 3 10 12 -1 indicates that only columns 0 through 3
** and columns 10 through 12 will be printed.
*/

/* 
** 2.预处理指令实现注释删除文本
** 即使statments代码段之间原先存在注释也无妨，不会出现问题。
*/
#if 0
	statments
#endif

/* 
** 3.预处理指令（preprocessor directives）：#include，#define
** - 预处理指令由预处理器（preprocessoor）解释，他们读入源代码解析并修改预处理指令，然后将修改过的源代码交给编译器。
** - #include： 预处理器使用 库函数头文件 的内容替换 #include 指令语句。
** - #define：定义 字面值常量 设常量名，[常量：不可以被赋值符赋值]，[常量名：使用大写和普通变量区区分开来]。
*/
#include <stdio.h> // <stdio.h> - 名叫 stdio.h 的库函数头文件。该头文件使我们可以访问标准I/O库（Standard I/O Library）中的函数，执行输入输出功能。
#include <stdlib.h>
#include <string.h>
#define	MAX_COLS	20	/* max # of columns to process */ /* 能够处理的最大列号 */
#define	MAX_INPUT	1000	/* max len of input & output lines */ /* 每个输入行的最大长度 */

/* 
** 4.函数原型（function prototype）
** - 告诉编译器将在源文件中定义的函数的特征，当这些函数被调用时，编译器就能根据函数原型对函数调用进行准确性检查。
** - 原型定义的结构：类型（函数的返回类型）+ 函数名字 + 函数期望接收的参数（参数类型 参数名字）
** - 注意：
** 		- 参数的名字并非必需。
** 		- void：表示函数不返回任何值
**		- const：表示函数的内部代码逻辑将不会修改函数调用者所传递的这两个参数。
**		- * 指针（pointer）：指定一个存储于计算机内存中的值的内存地址。
*/
int		read_column_numbers( int columns[], int max );
void	rearrange( char *output, char const *input,int 	n_columns, int const columns[] );

/* 
** 5.main函数
** - 每个C语言程序都必须有一个main函数，它是程序执行的起点
** - void：表示函数不接受任何参数。
*/
int main( void )
{
	/* 
	** 6.函数的局部变量
	** - 仅当前函数下可以访问，其他函数无法通过变量名访问它们，但是可以通过作为调用函数的参数传递给其他函数。
	*/
	int		n_columns;		/* # of columns to process */
	int		columns[MAX_COLS];	/* the columns to process */
	char	input[MAX_INPUT];	/* array for input line */
	char	output[MAX_INPUT];	/* array for output line */

	/*
	** Read the list of column numbers
	** - 软件开发开销最大的地方并非是编写而是维护，修改代码的第一步就是理解清楚代码的功能。
	** - 代码中勤添加注释可以使得其他人或许是自己在以后更加容易理解代码的功能。
	** - 调用函数时的参数传递：
	** 		- MAX_COLS-常量-传值调用：调用函数时，常量和变量是以传值形式传递给这个函数。在被调用函数中对变量参数的任何修改都会在函数返回时丢失，也就是被调用函数无法修改调用函数以传值形式传递给它的参数。
	**		- columns-数组名-传址调用：数组参数（如同 int columns[]）是以引用的形式进程传递。当调用函数修改数组参数的其中一个元素时，调用函数所传递的数组会被真实修改。
	*/
	n_columns = read_column_numbers( columns, MAX_COLS );

	/*
	** Read, process and print the remaining lines of input.
	** 7.gets 函数用于标准行输入 
	** - gets 函数读取一行文本存储于作为参数传递给它的input数组中，gets函数返回一个非NULL值表示一行已被成功读取。
	** - 输入的一行文本由一串字符组成，以一个换行符结尾，gets 函数丢弃行末尾的换行符并在该行的末尾存储一个'\0'字符。（'\0'是ASCII码，占用一个字节）
	** - C语言中字符串是一串以'\0'字符结尾的字符。
	*/
	while( gets( input ) != NULL ){
		/* 
		** 8.printf 函数执行格式化输出 
		** - printf 函数接收两个参数，第一个参数是指定输出格式的格式字符串，第二个参数是需要打印的值。
		** - 格式字符串：包含 格式指定符（格式代码、格式码） 和 普通字符。
		** 		- 普通字符：将按照原样逐字打印
		**		- 格式指定符：使得printf函数接收第二个参数的值按照它所指定的格式打印。 	
		*/
		printf( "Original input : %s\n", input );
		/* 
		** 9.函数调用中，output参数是调用函数处理后将要创建并返回 main 函数的答案，后面的 3 个参数是传递给函数的值。
		** - 
		*/
		rearrange( output, input, n_columns, columns );
		printf( "Rearranged line: %s\n", output );
	}

	/*
	** 10.EXIT_SUCCESS符号
	** - 向操作系统提示程序成功执行。
	** - 由stdlib.h 头文件定义 EXIT_FAILURE 和 EXIT_SUCCESS。
	*/
	return EXIT_SUCCESS;
}

/*
** Read the list of column numbers, ignoring any beyond the specified
** maximum.
*/
int
read_column_numbers( int columns[], int max )
{
	/* 
	** 声明变量 num 并初始化变量为 0 
	** 不进行初始化的变量的值将是一个不可预料的值。
	*/
	int	num = 0;
	int	ch;

	/*
	** Get the numbers, stopping at eof or when a number is < 0.
	** 11.scanf 函数执行格式化输入
	** - scanf 函数的第一个函数是格式字符串，剩余的参数（都是变量）用于存储函数所读取的输入数据。
	** 		- 格式化字符串：描述期望的输入类型。
	**		- scanf 函数调用中传入的变量参数，前面必须加上 "&" 符号，如果是数组参数中的下标引用，也要加上这个符号，因为实际参数是数组的某个特定元素，是一个变量。
	** - scanf 函数的返回值是 函数 成功转化并存储于 剩余参数中的值的个数。
	** - scanf 函数的 格式化字符串 使用 所有格式码（除了%c之外）时，输入值之前的空白（空格、换行符、制表符）会被跳过，输入值后面的空白表示该值输入的结束。
	**		- 所以使用 %s 格式码时输入字符串时，输入的字符串中间不能包含空白。
	**
	** - num < max：确保格式化输入函数不会读取过多的值，从而导致数组溢出。
	** - columns[num] >= 0：确保 格式化输入 转化并存储的内容是正数。
	*/
	while( num < max && scanf( "%d", &columns[num] ) == 1 && columns[num] >= 0 )
		num += 1;

	/*
	** Make sure we have an even number of inputs, as they are
	** supposed to be paired.
	*/
	if( num % 2 != 0 ){
		/* 
		** puts 函数是用于标准行输出
		** - puts 函数是 gets 函数的输出版本，它把指定的字符串写到标准输出并在末尾添加一个换行符。
		*/
		puts( "Last column number is not paired." );
		/*
		** 向操作系统提示程序执行出现了错误。
		*/
		exit( EXIT_FAILURE );
	}

	/*
	** Discard the rest of the line that contained the final number.
	** 12.scanf 函数对输入的值进行转换时，只会读取需要读取的字符，输入行中可能包含剩余的不能读取的其他字符或者作为输入行终止符的换行符，等待被读取。
	** - while 循环将丢弃这些剩余的字符，防止被解析保存进程序中。
	** - getchar 函数将从标准输入读取一个字符并返回它的值。如果不再存在任何字符可供读取将返回常量EOF，提示已经到达文件末尾。
	** - 如果 getchar 函数读取到 '\n'，即已经读取到最后一个字符，无需再进行读取。
	** - ;：该单独一个分号占一行为 空语句（empty statemen）表示这个地方需要出现一条语句但又无需执行任何任务，独占一行是为了避免读者认为接下来的语句是循环体的一部分。
	** - ch是整型：EOF是一个整数值，它的位数比字符类型要多。字符类型是小整型数，使用一个整数变量容纳字符值不会出现问题。
	**
	** putchar 函数是对应getchar函数的非格式化字符输出函数
	*/
	while( (ch = getchar()) != EOF && ch != '\n' )
		;
	/* 
	** 13.上述的写法是：C语言可以把赋值操作蕴含在while语句内部，这样就允许程序员消除冗余语句
	** 下面是原写法：原写法存在代码冗余，同样的代码出现两次。但是可读性好，容易理解，尽量选择容易理解，但是消除冗余利于代码后期维护。0
	*/
	#if 0
		ch = getchar();
		while (ch != EOF && ch != '\n')
			ch = getchar();
	#endif

	return num;
}

/*
** Process a line of input by concatenating the characters from
** the indicated columns.  The output line is then NUL terminated.
** 11.函数的形参为指针，实参为数组名
** - 形参：定义函数时参数的类型，实参：实际调用函数时传递给调用函数的参数。
** - 传址调用语义：当数组名作为实参时，实际上传递给函数的是一个指向数组起始位置的指针，也就是数组在计算机内存中的地址。
** - 被调用的函数可以使用实参（数组名）传入形参的形参参数名（存储该数组内存地址的指针）通过形参参数名和下标引用数组中的元素。
** - 被调用的函数修改了形参数组的元素，实际上将修改实参数组的对应元素。
** 12.
** - const 关键字用于形参的目的在于：这个参数的实参不会在被调用的函数中被修改（保证传入函数的数组中的元素不会被修改）
** 		- 声明该参数在函数中不能被修改。
**		- 导致编译器去验证是否违背以上的声明。
*/
void
rearrange( char *output, char const *input, int n_columns, int const columns[] )
 {
	int	col;		/* subscript for columns array */
	int	output_col;	/* output column counter */
	int	len;		/* length of input line */

	len = strlen( input );
	output_col = 0;

	/*
	** Process each pair of column numbers.
	** 13.for语句
	** - 第一个表达式：初始部分-只在循环开始前执行一次。
	** - 第二个表达式：测试部分-循环中每次执行开始前都要执行一次。
	** - 第三个表达式：调整部分-循环中每次执行完毕后都要执行一次，在下一次测试部分执行之前执行。
	** - for循环语句的三个表达式是可选的（可有可无），但是两个分号 ; 是不可以缺少的。
	** - for语句其实就是while语句的一种常用风格写法：(for循环的等价while循环写法)
	** col = 0;
	** while(col < n_columns){
	**		循环体语句
	** 		col += 2;
	** }
	*/
	for( col = 0; col < n_columns; col += 2 ){
		int	nchars = columns[col + 1] - columns[col] + 1;

		/*
		** If the input line isn't this long or the output
		** array is full, we're done.
		*/
		if( columns[col] >= len ||output_col == MAX_INPUT - 1 )
			break;

		/*
		** If there isn't room in the output array, only copy
		** what will fit.
		*/
		if( output_col + nchars > MAX_INPUT - 1 )
			nchars = MAX_INPUT - output_col - 1;

		/*
		** Copy the relevant data.
		** 14.strncpy 函数：
		** - 把选中的字符从输入行复制到输出行中的可用的下一个位置。
		** - 函数参数：
		**		- char *__restrict__ _Dest：目的字符串的起始地址（字符数组中空闲空间元素的起始位置）。
		**		- const char *__restrict__ _Source；源字符串的起始地址（字符数组中开始复制元素的起始位置）。
		**		- size_t _Count：需要复制的字符数。
		*/
		strncpy( output + output_col, input + columns[col], nchars );
		output_col += nchars;
	}

	/* 
	**	15.输出的字符数组，在末尾添加一个'\0' 作为输出的字符串的终止符。
	*/
	output[output_col] = '\0';
}
