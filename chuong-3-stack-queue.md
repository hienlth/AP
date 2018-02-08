# Chương 3: STL Stack, Queue

## 1. Stack

Stack \(last in, first out – LIFO\): phần tử vào stack sau cùng, là phần tử được lấy ra khỏi stack trước nhất.

Các hàm thành viên của lớp stack:

| Tên hàm | Mô tả | Kiểu trả về |
| :--- | :--- | :--- |
| empty\(\) | Kiểm tra stack rỗng | true hoặc false |
| size\(\) | Trả về số phần tử trong stack | size\_type |
| top\(\) | Trả về giá trị phần tử ở đỉnh stack | &lt;T&gt; |
| push\(&lt;T&gt;\) | Đưa một phần tử vào stack | void |
| pop\(\) | Xóa phần tử ở đỉnh stack | void |

## 2. Queue

Queue \(first in, first out – FIFO\): phần tử vào queue trước nhất, là phần tử được lấy ra khỏi queue trước nhất.

Các hàm thành viên của lớp queue:

| Tên hàm | Mô tả | Kiểu trả về |
| :--- | :--- | :--- |
| empty\(\) | Kiểm tra queue rỗng | true hoặc false |
| size\(\) | Trả về số phần tử trong queue | size\_type |
| front | Trả về giá trị phần tử đầu queue | &lt;T&gt; |
| back | Trả về giá trị phần tử cuối queue | &lt;T&gt; |
| push\(&lt;T&gt;\) | Thêm một phần tử vào cuối queue | void |
| push\_back\(&lt;T&gt;\) |  |  |
| pop\(\) | Xóa phần tử đầu queue | void |
| pop\_front\(\) |  |  |

## 3. Bài tập

### Bài tập 1:

Thực hiện đổi từ cơ số 10 sang cơ số X \(dùng stack\).

### Bài tập 2:

Cài đặt chương trình định giá trị của một biểu thức toán học thông thường \(ở dạng trung tố - Infix\). Trong đó, biểu thức toán học bao gồm các số nguyên không âm \(&gt;= 0\), các phép toán + - \* / \(cộng, trừ, nhân và chia\) và dấu ngoặc \( \).

#### Ví dụ:

INFIX : **3+4\*2/\(1-5\)**

POSTFIX : **3 4 2 \* 1 5 - / +**

Value : **1**

#### Hướng dẫn:

_**Bước 1**_: Chuyển từ Trung tố sang Hậu tố:

Thuật toán chuyển đổi biểu thức từ trung tố sang hậu tố:

* Nếu gặp 1 toán hạng \(con số hoặc biến\) thì nó ghi vào kết quả \(chuỗi kết quả là biểu thức hậu tố\).
* Nếu gặp dấu mở ngoặc thì đưa nó vào stack.
* Nếu gặp 1 toán tử \(ví dụ là t1\) thì thực hiện 2 bước sau:
  * Nếu stack rỗng hoặc toán tử t2 ở đỉnh stack có độ ưu tiên thấp hơn t1 thì ghi \(push\) t1vào ngăn xếp.
  * Nếu stack không rỗng, và còn toán tử t2 ở đỉnh ngăn xếp mà độ ưu tiên của t1 nhỏ hơn hay bằng độ ưu tiên của t2 thì lấy t2 ra khỏi ngăn xếp và ghi vào kết quả. Sau đó thêm t1 vào ngăn xếp.

* Nếu gặp dấu đóng ngoặc thì cứ lấy các tất cả các toán tử trong ngăn xếp ra và ghi vào kết quả cho đến khi lấy được dấu mở ngoặc ra khỏi ngăn xếp \(không ghi\).
* Khi đã duyệt hết biểu thức trung tố, lần lượt lấy tất cả toán tử \(nếu có\) từ ngăn xếp và ghi vào chuỗi kết quả.

> function INFIXTOPOSTFIX \(Expression P\) return Expression Q
>
> Khai báo biến ngăn xếp S
>
> while \(chưa hết biểu thức P\)
>
> Lấy 1 kí tự x trong P \(theo thứ tự trái qua phải\)
>
> if \(x là số\)
>
> Thêm x vào Q
>
> if \(x là dấu mở ngoặc\)
>
> S.Push\(x\)
>
> if \(x là toán tử\)
>
> while\( thứ tự ưu tiên S.TOP\(\) &gt;= x\)
>
> w &lt;- S.POP \(\)
>
> Thêm w vào Q
>
> S.Push\(x\)
>
> if \(x là dấu đóng ngoặc ‘\)’ \)
>
> while\(chưa gặp dấu mở ngoặc ‘\(‘ \)
>
> w &lt;- S.POP \(\)
>
> Thêm w vào Q
>
> S.POP \(\)//đẩy mở ngoặc ra khỏi stack
>
> while\(! S.IsEmpty\(\)\)
>
> w &lt;- S.POP \(\)
>
> if\(w không là mở ngoặc\)
>
> Thêm w vào Q

_**Bước 2**_**: **Định giá trị biểu thức:

function CALCULATEPOSTFIX \(Expression Q\) return value

Khai báo biến ngăn xếp S

foreach chuỗi x trong biểu thức Q do

if\(x là số\)

S.Push\(x\)

if \(x là toán tử\)

w1 = S.POP \(\)

w2 = S.POP \(\)

GiaTri = PHEPTOAN\(w2, w1\) //tính kết quả phép toán

S.Push\(GiaTri\)

value &lt;- S.POP \(\) //lúc này ngăn xếp chỉ còn lại 1 giá trị duy nhất

### Bài tập 3:\(\*\)

Cài đặt thuật toán Quick Sort dùng Stack để khử đệ quy.

