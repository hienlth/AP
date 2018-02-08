# A. LÝ THUYẾT

# 1.Con trỏ

Con trỏ là khái niệm đặc biệt trong C/C++ được dùng để chứa địa chỉ. Các thao tác với con trỏ:

* Khai báo biến con trỏ.
* Khởi tạo con trỏ dùng cấp phát vùng nhớ.
* Truy xuất giá trị ô nhớ từ biến con trỏ.
* Hủy vùng nhớ đã xin cấp phát.

## 1.1 Khai báo biến con trỏ

&lt;KieuDuLieu&gt; \*&lt;TenBien&gt;;

Ví dụ:

> int\* pa; // con trỏ đến kiểu int
>
> DIEM \*pd; // con trỏ đến kiểu DIEM

Toán tử **&**: dùng để xác định địa chỉ của một ô nhớ:

Ví dụ:

> int a = 1;
>
> int\* pa = &a;// con trỏ trỏ đến ô nhớ của biến a

## 1.2. Khởi tạo biến con trỏ dùng cấp phát vùng nhớ \(cấp phát động\)

Sử dụng toán tử new

_**Ví dụ:**_

> int\* pInt = new int; // xin cấp phát vùng nhớ cho 1 số nguyên
>
> DIEM \*pDiem = new DIEM;  // xin cấp phát vùng nhớ cho 1 biến kiểu cấu trúc DIEM

Toán tử new còn có thể sử dụng thể cấp phát vùng nhớ cho nhiều phần tử.

> int\* arr = new int\[5\]; // xin cấp phát vùng nhớ cho 5 số nguyên

_**Lưu ý:**_

Để kiểm tra cấp phát vùng nhớ thành công hay không, ta dùng con trỏ đặc biệt NULL.

NULL là con trỏ đặc biệt, có thể được gán cho các biến con trỏ của các kiểu dữ liệu khác nhau.

Ví dụ: Cả 2 con trỏ sau đây đều hợp lệ.

> int\* pInt = NULL;
>
> DIEM\* pDiem = NULL;

Để kiểm tra cấp phát thành công, ta làm như sau:

> DIEM\* pDiem = NULL; // khai báo con trỏ và gán bằng NULL
>
> pDiem = new DIEM; // xin cấp phát vùng nhớ
>
> if \(pDiem == NULL\)// nếu pDiem vẫn bằng NULL thì xin cấp phát không thành công
>
> cout&lt;&lt;“Cap phat khong thanh cong”;

## 1.3. Truy xuất giá trị ô nhớ từ biến con trỏ

### 1.3.1. Đối với các kiểu dữ liệu cơ bản \(như kiểu int, float, …\)

Toán tử \*: dùng để xác định giá trị ô nhớ tại địa chỉ trong biến con trỏ:

Ví dụ:

Với khai báo các biến a, pa:

> int a = 1;
>
> int\* pa = &a; // con trỏ trỏ đến ô nhớ của biến a

câu lệnh

> cout&lt;&lt;\*pa;

sẽ xuất ra “1”.

### 1.3.2. Đối với các kiểu dữ liệu cấu trúc \(như kiểu SINHVIEN, DIEM, …\)

Để truy xuất các thành phần của kiểu cấu trúc, dùng **-&gt;**

Ví dụ:

Với kiểu cấu trúc DIEM được định nghĩa như sau

> struct DIEM
>
> {
>
> int hoanhDo, tungDo;
>
> } ;
>
> DIEM \*pDiem = new DIEM;

Để truy xuất thành phần dùng: **pDiem-&gt;hoanhDo** và **pDiem-&gt;tungDo**

## 1.4. Hủy vùng nhớ đã xin cấp phát

Để hủy vùng nhớ đã xin cấp phát, dùng toán tử delete

Ví dụ đã khai báo 2 con trỏ pa, pb như sau:

> int\* pa = new int;
>
> int\* pb = new int\[5\];

thì cách hủy tương ứng sẽ là:

> delete pa;
>
> delete pb\[\];

## 1.5 Ví dụ Con trỏ cơ bản

> struct DIEM
>
> {
>
> int hoanhDo, tungDo;
>
> } ;
>
> void main\(\)
>
> {
>
> // khoi tao cac bien gia tri
>
> int a = 1;
>
> DIEM d;
>
> d.hoanhDo = 1;
>
> d.tungDo = 2;
>
> // khai bao bien con tro va tro den vung nho cua cac bien gia tri da co
>
> int \*pa = &a;
>
> int \*pb = pa;
>
> DIEM \*pd = &d;
>
> // xac dinh dia chi o nho: toan tu &
>
> cout&lt;&lt;"Dia chi o nho:"&lt;&lt;&a&lt;&lt;endl;
>
> // truy xuat gia tri o nho tu bien con tro: toan tu \*
>
> cout&lt;&lt;"Gia tri a:"&lt;&lt; \*pa&lt;&lt;endl;
>
> // truy xuat thanh phan trong cau truc
>
> cout&lt;&lt;"Diem D: \("&lt;&lt; d.hoanhDo &lt;&lt; “, “&lt;&lt; d.tungDo “\)”;//doi voi bien gia tri: .
>
> cout&lt;&lt;"Diem D: \("&lt;&lt; pd-&gt;hoanhDo &lt;&lt; ”,” &lt;&lt; pd-&gt;tungDo &lt;&lt;”\)”;// doi voi bien con tro: -&gt;
>
> delete pd;
>
> }

## 1.6. Con trỏ với mảng

Cách làm trước đây khi không sử dụng cấp phát động với mảng 1 chiều:

> int a\[100\];// cấp phát 100 ô nhớ cho mảng tối đa 100 phần tử

Cách làm này có nhiều hạn chế như: cấp phát thừa trong trường hợp n nhập vào &lt; 100 và không cho phép n nhập vào lớn hơn một số lượng định trước được cài đặt trong code \(100\).

Để cấp phát mảng động \(số lượng phần tử cấp phát đúng bằng với n nhập vào và không giới hạn giá trị n\), ta làm như sau:

> //khai bao bien con tro a va xin cap phat vung nho chua n so interger
>
> int\* a = new int\[n\];
>
> //dung vong lap de nhap cac gia tri a\[i\]
>
> for \(int i = 0; i &lt; n; i++\)
>
> {
>
> cout&lt;&lt;"Nhap a\["&lt;&lt;i&lt;&lt;"\]: ";
>
> cout&lt;&lt; a\[i\];
>
> }

Chú ý: Sau khai báo

> int\* a = new int\[n\];

một vùng nhớ chứa n số nguyên sẽ được cấp phát, con trỏ a sẽ chỉ đến phần tử đầu tiên của dãy n số.

Các phần tử của mảng được truy xuất qua toán tử \[\] như với mảng trước đây đã dùng.

# 2.ĐỌC XUẤT FILE VĂN BẢN

Link:[http://www.cplusplus.com/doc/tutorial/files/](http://www.cplusplus.com/doc/tutorial/files/)

Đối với C++, bạn sử dụng thư viện fstream.

* **ofstream**: dùng để ghi
* **ifstream**: dùng để đọc

Ví dụ:

> ofstream FileDemo \("File Demo.txt"\);
>
> FileDemo&lt;&lt;"Day la file demo su dung fstream";
>
> FileDemo.close\(\);

Có thể sử dụng hàm constructor để khởi tạo luôn tập tin dùng để đọc ghi hoặc khai báo phương thức open\(\) của chúng với tham số tùy chọn:

> **void open \(const char\* filename, ios::openmode mode\);**

| **Mode** | **Mô tả** |
| :--- | :--- |
| ios::app | Mở file để ghi thêm vào dòng cuối cùng. |
| ios::ate | Mở file để ghi và di chuyển con trỏ vào cuối file |
| ios::in | Mở file chỉ đọc |
| ios::out | Mở file để ghi |
| ios::trunc | Nếu file tồn tại, nội dung file sẽ bị xóa |
| ios::binary | Mở file ở chế độ nhị phân |

Ví dụ:

```
ofstream myfile;
```

```
myfile.open (
"
example.bin
"
, ios::out | ios::app | ios::binary);
```

Phương thức is\_open\(\): dùng để kiểm tra file có đang mở hay không.

Ví dụ đọc nội dung file text:

```
#include 
<
iostream
>
```

```
#include 
<
fstream
>
```

```
#include 
<
string
>
```

```
using
namespace
 std;
```

```

```

```
int
 main () {
```

```
string line;
```

```
ifstream myfile (
"
example.txt
"
);
```

```
if
 (myfile.is_open())
```

```
{
```

```
while
 ( getline (myfile,line) )
```

```
{
```

```
cout 
<
<
 line 
<
<
'\n'
;
```

```
}
```

```
myfile.close();
```

```
}
```

```

```

```
else
 cout 
<
<
"
Unable to open file
"
;
```

```

```

```
return
 0;
```

```
}
```

Các phương thức khác:

·bad\(\): trả về true nếu đọc/ghi bị lỗi \(tương tự cho fail\(\)\)

·eof\(\): trả về true nếu ở cuối file.

