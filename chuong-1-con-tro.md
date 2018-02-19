# Chương 2: Con trỏ

# 1. Lý thuyết

## 1.1. Con trỏ

Con trỏ là khái niệm đặc biệt trong C/C++ được dùng để chứa địa chỉ.

Các thao tác với con trỏ:

* Khai báo biến con trỏ;
* Khởi tạo con trỏ dùng cấp phát vùng nhớ;
* Truy xuất giá trị ô nhớ từ biến con trỏ;
* Hủy vùng nhớ đã xin cấp phát.

### 1.1.1 Khai báo biến con trỏ

**&lt;KieuDuLieu&gt; \*&lt;TenBien&gt;;**

Ví dụ:

> int\* pa; // con trỏ đến kiểu int
>
> DIEM \*pd; // con trỏ đến kiểu DIEM

Toán tử **&**: dùng để xác định địa chỉ của một ô nhớ:

Ví dụ:

> int a = 1;
>
> int\* pa = &a;// con trỏ trỏ đến ô nhớ của biến a

### 1.1.2. Khởi tạo biến con trỏ \(cấp phát động\)

Sử dụng toán tử **new**

_**Ví dụ:**_

> int\* pInt = new int; // xin cấp phát vùng nhớ cho 1 số nguyên
>
> DIEM \*pDiem = new DIEM;  // xin cấp phát vùng nhớ cho 1 biến kiểu cấu trúc DIEM

Toán tử new còn có thể sử dụng thể cấp phát vùng nhớ cho nhiều phần tử.

> int\* arr = new int\[5\]; // xin cấp phát vùng nhớ cho 5 số nguyên

_**Lưu ý:**_

Để kiểm tra cấp phát vùng nhớ thành công hay không, ta dùng con trỏ đặc biệt **NULL**.

Con trỏ **NULL **có thể được gán cho các biến con trỏ của các kiểu dữ liệu khác nhau.

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
> > cout&lt;&lt;“Cap phat khong thanh cong”;

### 1.1.3. Truy xuất giá trị ô nhớ từ biến con trỏ

#### a. Đối với các kiểu dữ liệu cơ bản \(int, float, …\)

Toán tử \*: dùng để xác định giá trị ô nhớ tại địa chỉ trong biến con trỏ:

Ví dụ:

Với khai báo các biến a, pa:

> int a = 1;
>
> int\* pa = &a; // con trỏ trỏ đến ô nhớ của biến a

câu lệnh

> cout&lt;&lt;\*pa;

sẽ xuất ra “1”.

#### b. Đối với các kiểu dữ liệu cấu trúc

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

### 1.1.4. Hủy vùng nhớ đã xin cấp phát

Để hủy vùng nhớ đã xin cấp phát, dùng toán tử **delete**

Ví dụ đã khai báo 2 con trỏ pa, pb như sau:

> int\* pa = new int;
>
> int\* pb = new int\[5\];

thì cách hủy tương ứng sẽ là:

> delete pa;
>
> delete pb\[\];

### 1.1.5 Ví dụ Con trỏ cơ bản

> struct DIEM
>
> {
>
> > int hoanhDo, tungDo;
>
> } ;



> void main\(\)
>
> {
>
> > // khoi tao cac bien gia tri
> >
> > int a = 1;
> >
> > DIEM d;
> >
> > d.hoanhDo = 1;
> >
> > d.tungDo = 2;
> >
> > // khai bao bien con tro va tro den vung nho cua cac bien gia tri da co
> >
> > int \*pa = &a;
> >
> > int \*pb = pa;
> >
> > DIEM \*pd = &d;
> >
> > // xac dinh dia chi o nho: toan tu &
> >
> > cout&lt;&lt;"Dia chi o nho:"&lt;&lt;&a&lt;&lt;endl;
> >
> > // truy xuat gia tri o nho tu bien con tro: toan tu \*
> >
> > cout&lt;&lt;"Gia tri a:"&lt;&lt; \*pa&lt;&lt;endl;
> >
> > // truy xuat thanh phan trong cau truc
> >
> > cout&lt;&lt;"Diem D: \("&lt;&lt; d.hoanhDo &lt;&lt; “, “&lt;&lt; d.tungDo “\)”;//doi voi bien gia tri: .
> >
> > cout&lt;&lt;"Diem D: \("&lt;&lt; pd-&gt;hoanhDo &lt;&lt; ”,” &lt;&lt; pd-&gt;tungDo &lt;&lt;”\)”;// doi voi bien con tro: -&gt;
> >
> > delete pd;
>
> }

### 1.1.6. Con trỏ với mảng

Cách làm trước đây khi không sử dụng cấp phát động với mảng 1 chiều:

> int a\[100\];// cấp phát 100 ô nhớ cho mảng tối đa 100 phần tử

Cách trên có nhiều hạn chế như: cấp phát thừa trong trường hợp n nhập vào &lt; 100 và không cho phép n nhập vào lớn hơn một số lượng định trước được cài đặt trong code \(100\).

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
> > cout&lt;&lt;"Nhap a\["&lt;&lt;i&lt;&lt;"\]: ";
> >
> > cout&lt;&lt; a\[i\];
>
> }

Chú ý: Sau khai báo

> int\* a = new int\[n\];

một vùng nhớ chứa n số nguyên sẽ được cấp phát, con trỏ a sẽ chỉ đến phần tử đầu tiên của dãy n số.

Các phần tử của mảng được truy xuất qua toán tử \[\] như với mảng trước đây đã dùng.

## 1.2. ĐỌC XUẤT FILE VĂN BẢN

Link tham khảo thêm các hàm: [http://www.cplusplus.com/doc/tutorial/files/](http://www.cplusplus.com/doc/tutorial/files/)

Đối với C++, bạn sử dụng thư viện **fstream**.

* **ofstream**: dùng để ghi
* **ifstream**: dùng để đọc

Ví dụ:

> ofstream FileDemo \("**File Demo.txt**"\);
>
> FileDemo&lt;&lt;"Day la file demo su dung fstream";
>
> FileDemo.**close**\(\);

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

> ofstream myfile;
>
> myfile.open \("example.bin", ios::out \| ios::app \| ios::binary\);

Phương thức **is\_open\(\)**: dùng để kiểm tra file có đang mở hay không.

Ví dụ đọc nội dung file text:

> \#include &lt;iostream&gt;
>
> \#include &lt;fstream&gt;
>
> \#include &lt;string&gt;
>
> using namespace std;



> int main \(\) {
>
> string line;
>
> ifstream myfile \("example.txt"\);
>
> if \(myfile.is\_open\(\)\)
>
> {
>
> > while \( getline \(myfile,line\) \)
> >
> > {
> >
> > > cout &lt;&lt; line &lt;&lt; '\n';
> >
> > }
> >
> > myfile.close\(\);
>
> }
>
> else cout &lt;&lt; "Unable to open file";
>
> return 0;
>
> }

Các phương thức khác:

* **bad\(\)**: trả về true nếu đọc/ghi bị lỗi \(tương tự cho **fail\(\)**\)
* **eof\(\)**: trả về true nếu ở cuối file.

# 2. Bài tập Thực hành

## **Bài tập 01:**

Viết chương trình nhập vào một số nguyên n. Sử dụng con trỏ để thực hiện các phép toán liên quan đến mảng một chiều:

* Nhập / xuất mảng.
* Tìm phần tử thỏa yêu cầu
* Tính tổng / tích / đếm các phần tử thỏa yêu cầu
* Sắp xếp tăng / giảm.

## Bài tập 02:

Tương tự bài tập 01 nhưng trên mảng 2 chiều \(con trỏ cấp 2\).

* Tổng các cột trên đường chéo chính.
* Kiểm tra A\(n,n\) có phải là ma trận đối xứng hay không?
* Xây dựng ma trận xoắn ốc
* Nhập vào A\(n, m\), B\(m, p\). Tính C = A + B và D = A \* B
* Liệt kê các điểm yên ngựa có trong ma trận.

_**Gợi ý:**_

Mảng 2 chiều mxn các số nguyên được khai báo như sau:

> int\*\* b = new int\*\[m\];

trong đó mỗi b\[i\] \(kiểu int\*\) là một mảng một chiều n số nguyên:

> b\[i\] = new int\[n\];

## Bài tập 03:

Mở rộng cho trường hợp đọc số phần tử từ file **INPUT.txt**, thực hiện sắp xếp và lưu kết quả xuống file **OUTPUT.txt**.

## Bài tập 04:

Sử dụng Con trỏ hàm để viết các hàm sắp xếp:

* Tăng dần
* Giảm dần
* Dương giảm rồi âm tăng, cuối cùng là số 0.

_**Hướng dẫn:**_

Khai báo các hàm cần thiết:

> void SapXep\(int \*a, int n, bool\(\*psort\)\(int, int\)\);
>
> bool Ascending\(int X, int Y\);
>
> bool Descending\(int X, int Y\);
>
> bool Chan\_Dau\_Day\(int X, int Y\);

Cài đặt các hàm:

> bool Ascending\(int X, int Y\){ return Y &lt; X; }
>
> bool Descending\(int X, int Y\){ return Y &gt; X; }
>
> bool Chan\_Dau\_Day\(int X, int Y\)
>
> {
>
> > //nếu y chẵn, x lẻ
> >
> > if \(\(Y % 2 == 0\) && \(X % 2 == 1\)\) return false;
> >
> > if \(\(X % 2 == 0\) && \(Y % 2 == 1\)\) return true;
> >
> > //ngược lại
> >
> > return Ascending\(X, Y\);
>
> }

Gọi hàm:

> SapXep\(A, n, Chan\_Dau\_Day\);

# 3. Bài tập Tự luyện

## Bài tập 01: Tính tiền lãi tiết kiệm

Giả sử lãi suất mỗi tháng của ngân hàng là q \(ví dụ nếu lãi suất 1% thì q=0.01\) với hình thức gởi tiết kiệm lãi nhập vốn.

_**Chú thích**_: Hình thức tiết kiệm lãi nhập vô là toàn bộ số tiền gốc và tiền lãi của tháng trước đó sẽ được cộng dồn lại thành tiền gốc của tháng tiếp theo và tiếp tục tính tiền lãi.

Viết chương trình cho người dùng nhập vào:

* số tiền gửi \(M\)
* số tháng gửi \(n\)
* lãi suất \(q\)

Tính và in ra tổng số tiền lãi. Sinh viên thực hiện bằng 2 cách: rút ra công thức tính nhanh và dùng vòng lặp.

**Ví dụ:              
**

M = 1000000, n = 3, q = 1.15

* Tháng thứ 1 được 1000000 + 0.015\*1000000 = 1015000
* Tháng thứ 2 được 1015000 + 0.015\*1015000 = 1030225
* Tháng thứ 3 được 1030225 + 0.015\*1030225 = …

## Bài tập 02: Đếm số tế bào sống sót

Trong phòng thí nghiệm Sinh, các sinh viên nuôi cấy tế bào phục vụ cho môn học. Các tế bào được nuôi có khả năng nhân đôi số lượng sau 1 ngày nuôi cấy. Tuy nhiên, do môi trường nuôi cấy không được tốt nên cứ sau d ngày sẽ có t% số tế bào bị chết đi. Ban đầu các sinh viên chọn n tế bào để nuôi cấy. Biết n, d, t, m là các giá trị nguyên dương.

Viết chương trình giúp cho người dùng nhập vào:

* Số tế bào ban đầu \(n\)
* Số ngày tế bào sẽ chết \(d\)
* Tỷ lệ tế bào chết \(t%\)
* Số ngày thí nghiệm \(m\)

Tính toán và xuất ra kết quả trên màn hình. Sinh viên thực hiện theo 2 cách: sử dụng công thức tính nhanh và dùng vòng lặp.

Ví dụ:

d = 2, t = 5, n = 100, m = 5

Số tế bào ban đầu là 100,

* Sau ngày thứ 2 số tế bào tăng lên là 400, chết đi 0.05\*400 = 20, vậy còn 380
* Sau ngày thứ 4 số tế bào là 1520, chết đi 0.05\*1520 = 76, vậy còn 1444
* Sau ngày thứ 5 số tế bào tăng lên là 2888

## Bài tập 03: Thao tác chuỗi ký tự

Cho người dùng nhập chuỗi S và lựa chọn các thao tác sau:

_**1.Đếm và cho biết số lượng khoảng trắng, số lượng  chữ số, số lượng chữ cái, số lượng các  kí tự khác**_  \(ví dụ: !@\*$...\).

Ví dụ:

* Nhập vào:

> DHSP 221, NVC, P4, Q5.

* Xuất ra:

> So luong chu so: 5
>
> So luong chua cai: 9
>
> So luong khoang trang: 4
>
> So luong ki tu khac: 4

_**2.Đếm số lượng từ của chuỗi, biết rằng các từ cách nhau bởi khoảng trắng.**_

Ví dụ:

* Nhập vào: \(tương tự ví dụ trên\)
* Xuất ra: Co 4 tu

* Chuyển đổi kí tự đầu mỗi từ thành kí tự in hoa, các kí tự khác in thường.

Ví dụ:

* Nhập vào: \(tương tự ví dụ trên\)
* Xuất ra: Dhsp 221 Nvc, P4, Q5.



