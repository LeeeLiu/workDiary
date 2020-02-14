

1. vector没有push_front，只有push_back。
2. 排序
>condition1=is_sorted(nums.begin(),nums.end()); //是否是升序
>sort(A.begin()+index, A.end()); 
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
