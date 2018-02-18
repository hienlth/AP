# _Chương 2: STL_

_Tham khảo thêm tại: _[http://www.cplusplus.com/reference/stl/](http://www.cplusplus.com/reference/stl/)

## 1.Lý thuyết

### 1.1 Giới thiệu

**S**tandard **T**emplate **L**ibrary - một thư viện template cho C++ với những cấu trúc dữ liệu cũng như giải thuật được xây dựng tổng quát mà vẫn tận dụng được hiệu năng và tốc độ của C. Với khái niệm template, những người lập trình đã đề ra khái niệm lập trình tổng quát \(generic programming\), C++ được cung cấp kèm với bộ thư viện chuẩn STL.

### 1.2 Các loại

Thư viện mẫu chuẩn STL trong C++ chia làm 4 thành phần là:

#### 1.2.1 Containers Library :

Chứa các cấu trúc dữ liệu mẫu \(template\)

* **Sequence containers: **vector, deque, list
* **Container adaptors: **stack, queue, priority\_queue
* **Associative containers**: set, multiset, map, multimap
* **Unordered associative containers: **unordered\_set, unordered\_multiset , unordered\_map, unordered\_multimap

#### 1.2.2 Algorithms Library:

Một số thuật toán để thao tác trên dữ liệu

#### 1.2.3 Iterator Library:

giống như con trỏ, dùng để truy cập đến các phần tử dữ liệu của container.

Trong C++, một biến lặp \(**iteraror**\) là một đối tượng bất kì, trỏ tới một số phần tử trong 1 phạm vi của các phần tử \(như mảng hoặc container\), có khả năng để lặp các phần tử trong phạm vi bằng cách sử dụng một tập các toán tử \(operators\) \(như so sánh, tăng \(++\),...\)

* Dạng rõ ràng nhất của iterator là một con trỏ: Một con trỏ có thể trỏ tới các phần tử trong mảng, và có thể lặp thông qua sử dụng toán tử tăng \(++\). Tuy nhiên, cũng có các dạng khác của iterator. Ví dụ: mỗi loại container \(chẳng hạn như vector\) có một loại iterator được thiết kế để lặp các phần tử của nó một cách hiệu quả.
* Iterator có các toán tử như:
  * So sánh: “==” , “**!=**” giữa 2 iterator.
  * Gán: “**=**” giữa 2 iterator.
  * Cộng trừ: “**+**”, ”**-**“ với hằng số và ”**++**”, ”**--**“.
  * Lấy giá trị: “**\***”.

Ví dụ:

> /\*khai  báo iterator  “it”\*/
>
> vector &lt;int&gt; :: **iterator  **it;
>
>  
>
> /\* trỏ  đến vị  trí phần  tử  đầu tiên  của vector \*/
>
> it=vector.**begin**\(\);
>
>  
>
> /\*trỏ  đến vị trí kết  thúc \(không  phải  phần tử  cuối  cùng nhé\) của vector\)  \*/
>
> it=vector.**end**\(\);
>
>  
>
> /\* khai  báo iterator ngược  “rit” \*/
>
> vector &lt;int&gt; :: **reverse\_iterator **rit;
>
> rit =  vector.**rbegin**\(\);
>
>  
>
> /\* trỏ  đến vị  trí kết thúc của vector theo  chiều  ngược \(không phải  phần tử đầu tiên  nhé\*/
>
> rit =  vector.**rend**\(\);

#### 1.2.4 Numeric library

### 1.3 Sử dụng

Để sử dụng STL, bạn cần khai báo từ khóa “**using namespace std;**” sau các khai báo thư viện \(các “\#include”, hay “\#define”,...\)

Ví dụ:

> \#include &lt;iostream&gt;
>
> \#include &lt;stack&gt;       //khai  báo sử dụng container stack
>
>
>
> \#define N  100
>
>
>
> using  namespace std;  //khai báo sử dụng STL
>
>
>
> int main\(\)  {
>
> > ...
> >
> > return 0;
>
> }



