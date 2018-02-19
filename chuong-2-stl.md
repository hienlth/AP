# _Chương 3: STL_

_Tham khảo thêm tại: _[http://www.cplusplus.com/reference/stl/](http://www.cplusplus.com/reference/stl/)

## 1.Lý thuyết

### 1.1 Giới thiệu

**S**tandard **T**emplate **L**ibrary - một thư viện template cho C++ với những cấu trúc dữ liệu cũng như giải thuật được xây dựng tổng quát mà vẫn tận dụng được hiệu năng và tốc độ của C. Với khái niệm template, những người lập trình đã đề ra khái niệm lập trình tổng quát \(generic programming\), C++ được cung cấp kèm với bộ thư viện chuẩn STL.

### 1.2 Các loại

Thư viện mẫu chuẩn STL trong C++ chia làm 3 thành phần là:

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

* Dạng rõ ràng nhất của iterator là một con trỏ: Một con trỏ có thể trỏ tới các phần tử trong mảng, và có thể lặp thông qua sử dụng toán tử tăng \(++\). Tuy nhiên, cũng có các dạng khác của iterator. Ví dụ: mỗi loại container \(chẳng hạn như vector\) có một loại iterator được thiết kế để lặp các phần tử của nó một cách hiệu quả.
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
> /\* trỏ  đến vị  trí phần  tử  đầu tiên  của vector \*/
>
> it=vector.**begin**\(\);
>
> /\*trỏ  đến vị trí kết  thúc \(không  phải  phần tử  cuối  cùng nhé\) của vector\)  \*/
>
> it=vector.**end**\(\);
>
> /\* khai  báo iterator ngược  “rit” \*/
>
> vector &lt;int&gt; :: **reverse\_iterator **rit;
>
> rit =  vector.**rbegin**\(\);
>
> /\* trỏ  đến vị  trí kết thúc của vector theo  chiều  ngược \(không phải  phần tử đầu tiên  nhé\*/
>
> rit =  vector.**rend**\(\);

#### 1.3 Sử dụng

Để sử dụng STL, bạn cần khai báo từ khóa “**using namespace std;**” sau các khai báo thư viện \(các “\#include”, hay “\#define”,...\)

Ví dụ:

> \#include &lt;stack&gt;       //khai  báo sử dụng container stack
>
> \#define N  100
>
> using  namespace std;  //khai báo sử dụng STL
>
> int main\(\)  {
>
> > ...
> >
> > return 0;
>
> }

### 1.4 Mảng động - VECTOR

#### 1.4.1 Khai báo:

**vector&lt;kiểu&gt; biến;**

**vector&lt;kiểu&gt; biến\(số\_phần\_tử\);**

**vector&lt;kiểu&gt; biến\(**_**sốphầntử, giátrịmộtphầntử**_**\);**

#### 1.4.2 Ví dụ:

/\*  Vector 1 chiều \*/

> **vector &lt;int&gt; A;** /\* tạo vector rỗng kiểu dữ liệu int \*/
>
> **vector &lt;int&gt; B\(5,777\); **/\*tạo vector với 5 phần tử là 777 \*/
>
> **vector &lt;int&gt; C \(B.begin\(\),B.end\(\)\); **/\*lấy từ đầu đến cuối vector B \*/
>
> **vector &lt;int&gt; D\(C\);** //copy từ vector C

/\* Vector 2 chiều\*/

> **vector &lt; vector &lt;int&gt; &gt; v;** /\* Tạo vector 2 chiều rỗng \*/
>
> **vector &lt; vector &lt;int&gt; &gt; v \(5,  10\);** /\* khai báo vector 5×10 \*/
>
> **vector &lt; vector &lt;int&gt; &gt;  v \(5\);** /\* khai báo 5  vector 1 chiều rỗng \*/
>
> **vector &lt; vector &lt;int&gt; &gt;  v \(5, vector &lt;int&gt; \(10,1\)\);** /\*khai báo vector 5\*10 với các phần tử khởi tạo giá trị là 1\*/

#### 1.4.3 Các hàm thành  viên:

* **capacity**: số lượng tối đa có thể đáp ứng tại thời điểm gọi.
* **size **: trả  về số lượng  phần tử  của vector.
* **empty  **: trả  về true\(1\)  nếu vector  rỗng,  ngược lại là  false\(0\).

#### 1.4.4 Truy cập tới phần tử:

* **operator \[i\]**  : trả về giá trị phần tử thứ  **i**.
* **at **: tương tự như trên.
* **front**: trả  về giá  trị phần tử đầu tiên.
* **back**: trả  về giá trị phần  tử cuối cùng.

#### 1.4.5 Chỉnh sửa:

* **push\_back **: thêm  vào ở  cuối vector.
* **pop\_back  **: loại bỏ phần tử ở cuối vector.
* **insert \(iterator,x\)**: chèn “x”  vào trước  vị trí “iterator” \(x  có thể là  phần tử  hay iterator của 1  đoạn  phần tử…\).
* **erase **: xóa phần tử  ở  vị trí iterator.
* **swap  **: đổi 2 vector cho nhau \(ví dụ: A.swap\(B\);\).
* **clear**: xóa vector.

## 2. Bài tập

### Bài tập 1:

Sử dụng container vector, anh/chị hãy viết chương trình đọc vào các số nguyên, sau đó loại bỏ các số chính phương trong vector rồi xuất ra các số chẵn theo thứ tự tăng dần.

### Bài tập 2:

Viết chương trình hoàn chỉnh cho bài toán sau:

Nhập vào một dãy số nguyên dương gồm N phần tử từ tập tin “**input.tx**t” theo cấu trúc:

* Dòng đầu ghi số nguyên dương N.
* N dòng tiếp theo, mỗi dòng ghi một số nguyên dương.

Yêu cầu: Xét mọi số nguyên trong dãy đã cho, nếu số đó là số nguyên tố thì yêu cầu tính tổng các chữ số không phải là số nguyên tố của nó, ngược lại xuất -1.

Dữ liệu xuất ra được ghi vào tập tin “**output.txt**”.

![](/assets/stl.PNG)

### Bài tập 3:

Viết hàm kiểm tra một chuỗi có phải là chuỗi đối xứng không?

Viết hàm xác định số lượng từ trong một chuỗi, xuất các từ có trong chuỗi.

Ví dụ:

**anh yeu em em yeu anh** -&gt; _**Chuỗi đối xứng**_

Số từ: **6  
**

Các từ có trong chuỗi:** anh yeu em  
**

