

### 知识点
1. 如果使用循环，程序的性能可能更高；如果使用递归，可读性更好。如何选择要看什么对你来说更重要。
    - 所有递归都能改写成循环吗？可以。有些递归只需要一个循环就可以替代，而有些递归的改写需要循环+栈。（比如二叉树dfs）
    - 所有循环都能改写成递归吗？可以但没必要。
[来自](http://stackoverflow.com/a/72694/139117)。（递归：空间复杂度就是O(n)。）
2. 对于尾递归，通常地，编译器已经优化成循环。
3. 浅复制与深复制
- 浅复制会将对象所有成员的值复制到另一个对象里。
- 深复制在此基础上，还会进一步复制所有指针对象。
- 多数情况下，使用浅复制是为了传递一块复杂结构的信息，但又不想真的复制一份数据。
- 实际开发中，很少用浅复制。大部分情况下，都会使用深复制。
4. Java处理输入、输出，时间比C++长很多。
5. 随机数有关
  -[srand((unsigned)time(NULL))要放在main里，不是循环/局部函数里](https://www.icourse163.org/forum/1001974001/topic-1004795563.htm?sortType=1&pageIndex=1)



### C++知识点
1. vector没有push_front，只有push_back。
2. 排序
>condition1=is_sorted(nums.begin(),nums.end()); //是否是升序
>sort(A.begin()+index, A.end()); //递增
>sort(vec.rbegin(), vec.rend()); //递减
>reverse(A.begin(),A.end());
3. 插入
nums.insert(nums.begin()+i,value); // A.begin()是在前面插入，A.end()是在后面插入
4. 删除：
string.erase()三种用法：
（1）erase(index, n); 删除从index开始的多个(n)字符（i从0开始）
（2）erase(iterator);删除iterator处的1个字符
（3）erase(iterator1, iterator2);删除从iterator1到iterator2之间的字符
如：
>str.erase(i, 1);
>A.erase( A.begin()+i );    //A是vector或string
>str.erase (str.begin()+5, str.end()-7);
5. 删除尾部元素
>even.pop_back(); 
5. 取尾部元素，取头部元素             
A[i]=even.back();   A[i]=even.front()

6. remove
remove的作用是将值为val的元素都移动到末尾，返回新的迭代器end()（非val部分的end）
但原vector的end并没有发生改变，size也就没有变化.
>两者结合应用：删除vector中所有值为x的元素
vec.erase(remove(vec.begin(),vec.end(),x),vec.end());
具体可参见leetcode 26

6. map、hash_map
>STL的map底层是用红黑树实现的，查找时间复杂度是log(n)；
hash_map底层是用hash表存储的，查询时间复杂度是O(1)，空间复杂度是O(n)。
所以数据量太大的时候，空间消耗很大。
>C++中的map、unordered_map，相当于java中的TreeMap、HashMap。

>map判断一个key是否出现：
count统计的是key出现的次数，只能为0/1；而find基于迭代器实现，以mp.end()判断是否找到要求的key。
if(m.count(key)!=0)   
if(m.find(key)!=m.end())
7. substr:
string a = s.substr(0,5); //获得字符串s中从第0位开始的长度为5的字串
8. auto关键字
```
#include<iostream>
using namespace std;
int main()
{
    string s("hello world");
    for(auto c:s)
    c='t';
    cout<<s<<endl;//结果为hello world
    for(auto &c:s)
    c='t';
    cout<<s<<endl; //结果为ttttttttttt
```
9. pair用法
    - pair <string,double> A ("tomatoes",3.25);
    - pair <int, int>A = make_pair(1, 2);
      pair <string,double> C = make_pair ("shoes",20.0);	
    - pair <string,int> B;  B.first ="aa";  B.second = 99;
10. 局部、全局变量，没有初始化的区别
  - 局部变量，都是存在栈中的。而栈往往是会快速重复的大量使用，如果每次使用都初始化，开销会比较大。不如，直接让程序员来手动初始化。
  - 相反，全局变量，存储的空间不会快速大量重复的使用，存活时间很长，所以初始化一下，开销并不会很大。
11. virtual关键字
  - `虚函数`有利于类多态：派生类对基类同名函数的“本地改造”，同一方法->不同结果。
  - `虚基类`：避免"菱形继承"造成的二义性。
    * 在构造派生类时，最终派生类中含有多个同一个基类的情况，就会产生二义性的问题（不知道该调用哪个基类的成员变量和函数），为解决此问题，需要使用虚基类，即只对此基类生成一块内存区域，这样最终派生类中就只含有一个基类。
    ```
    "菱形继承"（多继承的两个或以上父级 继承同一个祖级）
        A 
     /     \ 
    B       C 
     \     / 
        D
    ```  
  - `纯虚函数`：若一个类的成员函数被声明为纯虚函数，则意味着该类是抽象基类，即只能被继承，而不能用来声明对象。纯虚函数需要在类声明的后面加上关键词“=0”。