# _Chương 2: STL_

_Tham khảo thêm tại: **http://www.cplusplus.com/reference/stl/**_

## 1.Lý thuyết

### 1.1 Giới thiệu

Standard Template Library - một thư viện template cho C++ với những cấu trúc dữ liệu cũng như giải thuật được xây dựng tổng quát mà vẫn tận dụng được hiệu năng và tốc độ của C. Với khái niệm template, những người lập trình đã đề ra khái niệm lập trình tổng quát \(generic programming\), C++ được cung cấp kèm với bộ thư viện chuẩn STL.

### 1.2 Các loại

Thư viện mẫu chuẩn STL trong C++ chia làm 4 thành phần là:

#### 1.2.1 Containers Library : 

Chứa các cấu trúc dữ liệu mẫu \(template\)

* **Sequence containers  :**
* > Vector
  > Deque
  > List
* **Container adaptors**
* > Stack
  > Queue
  > Priority\_queue
* **Associative containers  **
* > Set
  > Multiset
  > Map
  > Multimap
  > Bitset

* **Unordered associative containers**
* > unordered\_set
  > unordered\_multiset 
  > unordered\_map 
  > unordered\_multimap

#### 1.2.2 Algorithms Library: 

Một số thuật toán để thao tác trên dữ liệu

#### 1.2.3 Iterator Library: 

giống như con trỏ, dùng để truy cập đến các phần tử dữ liệu của container.

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



