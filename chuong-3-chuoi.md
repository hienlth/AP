## Chương 4: CHUỖI

## 1. Lý thuyết

### 1.1 Khái niệm

Chuỗi ký tự là một dãy gồm các ký tự \(kiểu char\) hoặc một mảng các ký tự được kết thúc bằng ký tự ‘**\0**’ \(còn được gọi là ký tự 

**NULL** trong bảng mã ASCII\). Các hằng chuỗi ký tự được đặt trong cặp dấu nháy kép “”.

### 1.2 Khai báo

#### 1.2.1 Khai báo dạng mảng

Cú pháp: 

> char &lt;Biến&gt; \[Chiều dài tối đa\]

Ví dụ: Ta khai báo:

> char **Ten**\[12\];

nghĩa là bộ nhớ sẽ cung cấp 12+1 bytes để lưu trữ nội dung của chuỗi ký tự **Ten**; byte cuối cùng lưu trữ ký tự ‘\0’ để kết thúc chuỗi.

_Ghi chú:_

* Chiều dài tối đa của biến chuỗi là một hằng nguyên nằm trong khoảng từ 1 đến 255 bytes.
* Chiều dài tối đa không nên khai báo thừa để tránh lãng phí bộ nhớ, nhưng cũng không nên khai báo thiếu  .

#### 1.2.2 Khai báo dạng con trỏ

Cú pháp: 

> char \*&lt;Biến&gt;

Ví dụ: Ta khai báo:

> char \*Ten;

nghĩa là, bộ nhớ sẽ dành 2 byte để lưu trữ địa chỉ của biến con trỏ Ten đang chỉ đến, chưa cung cấp nơi để lưu trữ dữ liệu. Muốn có chỗ để lưu trữ dữ liệu, ta phải khởi tạo đối tượng bằng từ khóa new, sau đó mới gán dữ liệu cho biến.

#### 1.2.3 Ví dụ

Cú pháp: 

> char &lt;Biến&gt; \[\]= &lt;“Hằng chuỗi”&gt;

hoặc:

> char &lt;bien&gt; \[\] = {‘H’, ‘I’, ‘E’, ‘N’, ‘\0’};

Ví dụ:

> \#include &lt;iostream&gt;
>
> using namespace std;
>
> int main\(\)
>
> {
>
> > char Chuoi\[\]="Mau nang hay la mau mat em” ;
> >
> > cout&lt;&lt;"Vua khai bao vua gan tri : ”&lt;&lt;Chuoi&lt;&lt;endl;
> >
> > return 0;
>
> }

\* Ghi chú:

* Chuỗi được khai báo là một mảng các ký tự nên các thao tác trên mảng có thể áp dụng đối với chuỗi ký tự.
* Không thể gán giá trị sau khi khai báo. Ví dụ: chuoi = “Nguyen Van A”;//không hợp lệ.





## 2. Bài tập

### Bài tập 1

Viết chương trình nhập một chuỗi ký tự từ bàn phím. Hãy:

1. Xuất ra màn hình mã ASCII của từng ký tự có trong chuỗi.
2. Xuất ra màn hình chuỗi đảo ngược của chuỗi đó. Ví dụ đảo của “**abcd egh**” là “**hge dcba**”.
3. Mở rộng: In ra chuỗi đảo ngược theo từng từ. VD: chuỗi “**Happy Halloween**” đảo thành “**yppaH neewollaH**”.
4. Đếm có bao nhiêu khoảng trắng trong chuỗi.
5. Loại bỏ những khoảng trắng thừa trong chuỗi.

### Bài tập 2

Viết chương trình nhập một chuỗi ký tự và kiểm tra xem chuỗi đó có đối xứng không. Ví dụ : Chuỗi ABCDEDCBA là chuỗi đối xứng.

### Bài tập 3

Nhập vào một chuỗi bất kỳ, hãy đếm số lần xuất hiện của mỗi loại ký tự.

### Bài tập 4

Viết chương trình nhập vào một chuỗi rồi xuất chuỗi đó ra màn hình dưới dạng mỗi từ một dòng.

Ví dụ: “**Lap trinh nang cao**”

In ra :

> Lap
>
> trinh
>
> nang
>
> cao

### Bài tập 5

Viết chương trình đổi số tiền từ số thành chữ.

### Bài tập 6

Viết chương trình nhập vào họ và tên của một người. Sau đó thực hiện:

1. Cắt bỏ các khoảng trống không cần thiết \(nếu có\), tách tên ra khỏi họ và tên, in tên lên màn hình. Chú ý đến trường hợp cả họ và tên chỉ có một từ.
2. Cắt bỏ các khoảng trắng bên phải, trái và các khoảng trắng không có nghĩa trong chuỗi. In ra màn hình toàn bộ họ tên người đó dưới dạng chữ hoa, chữ thường.

### Bài tập 7

Viết chương trình nhập vào một danh sách họ và tên của n người theo kiểu chữ thường, đổi các chữ cái đầu của họ, tên và chữ lót của mỗi người thành chữ hoa. In kết quả lên màn hình.

### Bài tập 8

Viết chương trình nhập vào một danh sách họ và tên của n người, tách tên từng người ra khỏi họ và tên rồi sắp xếp danh sách tên theo thứ tự từ điển. In danh sách họ và tên sau khi đã sắp xếp.

