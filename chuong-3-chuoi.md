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

_Ghi chú:    
_

* Chiều dài tối đa của biến chuỗi là một hằng nguyên nằm trong khoảng từ 1 đến 255 bytes.
* Chiều dài tối đa không nên khai báo thừa để tránh lãng phí bộ nhớ, nhưng cũng không nên khai báo thiếu
  .

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

### 1.3 Các thao tác trên chuỗi ký tự

#### 1.3.1 Nhập xuất chuỗi

##### a. Nhập chuỗi từ bàn phím

Để nhập một chuỗi ký tự từ bàn phím, ta sử dụng hàm gets\(\)

Cú pháp:

> gets\(&lt;Biến chuỗi&gt;\)

Ví dụ:

> char Ten\[20\];
>
> gets\(Ten\);

Ta cũng có thể sử dụng hàm cout để nhập dữ liệu cho biến chuỗi, tuy nhiên lúc này ta chỉ có thể nhập được một chuỗi không có dấu khoảng trắng, dấu tab, dấu xuống dòng.

Hiện tại Visual Studio không cho dùng gets do nó unsafe \(Dangerous Function – theo OWASP\).

##### b. CIN.GETLINE\(\)

Đọc toàn bộ chuỗi văn bản được nhập vào.Cấu trúc:

> cin.getline\(char \*charPtr, int n, char delim = ‘\n’\);

Trong đó:

* charPtr là con trỏ trỏ đến mảng ký tự \(tên mảng cũng là con trỏ, nhưng là con trỏ hằng\).

* n là số ký tự tối đa được chứa trong mảng, kể cả ký tự ‘’

+delim là ký tự phân cách \(delimiter character\), mặc định là ký tự ‘\n’

•    Hàm getline đọc chuỗi cho đến khi gặp ký tự phân cách, hoặc ký hiệu kết thúc tập tin \(ctrl – z\), hoặc khi số ký tự đã đọc nhỏ hơn một so với giá trị n trong đối số thứ 2. Nếu ký tự phân cách được gặp, nó được lấy ra khỏi istream và bỏ đi.

Ví dụ:

> char name\[10\];
>
> cin.getline\(name, 10, ‘.’\);

Nếu nhập : A B. C

Mảng name sẽ là : A B

•    Con trỏ thì phải cấp phát mới dùng được.

##### c. Xuất chuỗi lên màn hình

Để xuất một chuỗi \(biểu thức chuỗi\) lên màn hình, ta sử dụng hàm puts\(\).

Cú pháp: puts\(&lt;Biểu thức chuỗi&gt;\)

Ví dụ: Nhập vào một chuỗi và hiển thị trên màn hình chuỗi vừa nhập.

> \#include&lt;iostream&gt;
>
> using namspace std;
>
> \#include&lt;cstring&gt;
>
> int main\(\)
>
> {
>
> > char Ten\[12\];
> >
> > cout&lt;&lt;"Nhap chuoi: "; cin.getline\(Ten, 20\);
> >
> > cout&lt;&lt;"Chuoi vua nhap: "; puts\(Ten\);
> >
> > return 0;
>
> }

Ngoài ra, ta có thể sử dụng hàm cout để hiển thị chuỗi lên màn hình.

##### c. Hàm thành viên get\(\)

> int cin.get\(\);
>
> cin.get\(char &cRef\);// cRef là tham chiếu đến biến kiểu char
>
> cin.get\(char \*charPtr, int n, char delim = ‘\n’\);

a\)    Hàm get\(\) không đối số, đọc một ký tự từ luồng nhập\(kể cả ký tự trắng\) và trả về ký tự này. Nếu là ký tự kết thúc tập tin thì hàm trả về EOF \(EOF có giá trị khác nhau trên những hệ thống khác nhau\).

Ví dụ:

> while\( \( c = cin.get\(\) \) != EOF\)
>
> > cout &lt;&lt; c;

   

Đoạn chương trình trên sẽ đọc từng ký tự của chuỗi nhập vào truyền vào biến c và xuất ra màn hình. Nếu người dùng nhập vào ký hiệu kết thúc tập tin \(end-of-file\) là tổ hợp phím ctrl-z thì vòng lặp kết thúc.

b\) Hàm thành viên get\(\) với một đối số kiểu char đọc một ký tự từ luồng nhập \(kể cả ký tự trắng\) và chứa trong đối số đó. Trả vế 0 khi ký hiệu kết thúc tập tin được gặp. ngược lại trả về tham chiếu đến đối tượng istream.

c\) Hàm thành viên get\(\) dạng thứ 3 hoạt động tương tự như hàm thành viên getline\(\), nhưng ký tự phân cách không được lấy ra mà  còn trên luồng nhập. Vì thế hàm get\(\) kế tiếp sẽ là dòng trống. Để loại bỏ có thể dùng dạng 1 hoặc 2 của hàm get\(\), hoặc hàm thành viên ignore\(\).

##### d. Hàm thành viên ignore\(\)

> cin.ignore\(int n = 1, int delim = EOF\);

bỏ qua một số ký tự được chỉ định \(mặc định là một ký tự\) trong luồng nhập hoặc bỏ qua cho đến khi ký tự phân cách \(mặc định là EOF\) được gặp. Mục đích là không làm ảnh hưởng các lệnh nhập tiếp theo.

#### 1.3.2 Một số hàm xử lý chuỗi \(trong &lt;cstring&gt;\)

##### a. Cộng chuỗi - Hàm strcat\(\)

Cú pháp: 

> **char \*strcat\(char \*des, const char \*source\)**

Hàm này có tác dụng ghép chuỗi nguồn vào chuỗi đích.

##### b. Xác định độ dài chuỗi - Hàm strlen\(\)

Cú pháp: 

> **int strlen\(const char\* s\)**

##### c. Sao chép chuỗi, hàm strcpy\(\)

Hàm này được dùng để sao chép toàn bộ nội dung của chuỗi nguồn vào chuỗi đích.

Cú pháp: 

> **char \*strcpy\(char \*Des, const char \*Source\)**

##### d. Sao chép một phần chuỗi, hàm strncpy\(\)

Hàm này cho phép chép n ký tự đầu tiên của chuỗi nguồn sang chuỗi đích.

Cú pháp: 

> **char \*strncpy\(char \*Des, const char \*Source, size\_t n\)**

##### e. Trích một phần chuỗi, hàm strchr\(\)

Để trích một chuỗi con của một chuỗi ký tự bắt đầu từ một ký tự được chỉ định trong chuỗi cho đến hết chuỗi, ta sử dụng hàm strchr\(\).

Cú pháp : 

> **char \*strchr\(const char \*str, int c\)**

Ghi chú:

* Nếu ký tự đã chỉ định không có trong chuỗi, kết quả trả về là NULL.
* Kết quả trả về của hàm là một con trỏ, con trỏ này chỉ đến ký tự c được tìm thấy đầu tiên trong chuỗi str.

##### f. Tìm kiếm nội dung chuỗi, hàm strstr\(\)

Hàm **strstr**\(\) được sử dụng để tìm kiếm sự xuất hiện đầu tiên của chuỗi s2 trong chuỗi s1.

Cú pháp: 

> **char \*strstr\(const char \*s1, const char \*s2\)**

Kết quả trả về của hàm là một con trỏ chỉ đến phần tử đầu tiên của chuỗi s1 có chứa chuỗi s2 hoặc giá trị NULL nếu chuỗi s2 không có trong chuỗi s1.

##### g. So sánh chuỗi, hàm strcmp\(\)

Để so sánh hai chuỗi theo từng ký tự trong bảng mã Ascii, ta có thể sử dụng hàm strcmp\(\).

Cú pháp:

> **int strcmp\(const char \*s1, const char \*s2\)**

Hai chuỗi s1 và s2 được so sánh với nhau, kết quả trả về là một số nguyên \(số này có được bằng cách lấy ký tự của s1 trừ ký tự của s2 tại vị trí đầu tiên xảy ra sự khác nhau\).

* Nếu kết quả là số âm, chuỗi s1 nhỏ hơn chuỗi s2.

* Nếu kết quả là 0, hai chuỗi bằng nhau.

* Nếu kết quả là số dương, chuỗi s1 lớn hơn chuỗi s2.

##### h. So sánh chuỗi, hàm strncmp\(\)

Hàm này thực hiện việc so sánh trong num ký tự đầu tiên của 2 chuỗi s1 và s2, giữa chữ thường và chữ hoa không phân biệt.

Cú pháp: 

> **int stricmp\(const char \*s1, const char \*s2, size\_t num\)**

Kết quả trả về tương tự như kết quả trả về của hàm strcmp\(\)

##### i. Khởi tạo chuỗi, hàm memset\(\)

Hàm này được sử dụng để đặt n ký tự đầu tiên của chuỗi là ký tự c.

Cú pháp: 

> **memset\(char \*Des, int c, size\_t n\)**

#### 1.3.3 Đổi từ chuỗi ra số, hàm atoi\(\), atof\(\), atol\(\) \(trong &lt;cstdlib&gt;\)

Để chuyển đổi chuỗi ra số, ta sử dụng các hàm trên.

Cú pháp :

> int atoi\(const char \*s\) : chuyển chuỗi thành số nguyên
>
> long atol\(const char \*s\) : chuyển chuỗi thành số nguyên dài
>
> float atof\(const char \*s\) : chuyển chuỗi thành số thực

Nếu chuyển đổi không thành công, kết quả trả về của các hàm là 0.

Ngoài ra, thư viện cstdlib còn hỗ trợ các hàm xử lý chuỗi khác, ta có thể đọc thêm trong phần trợ giúp.

#### 1.3.4 Các hàm xử lý ký tự thuộc thư viện &lt;cctype&gt;

* Hàm **int toupper\(int ch\)** : trả về giá trị là ký tự ch đã in hoa
* Hàm** int tolower\(int ch\)** : trả về giá trị là ký tự ch đã in thường
* Hàm **int isupper\(int ch\)** : kiểm tra ký tự ch có in hoa hay không \(trả về giá trị 0 : sai, 1 : đúng\)
* Hàm **int islower\(int ch\)** : kiểm tra ký tự ch có in thuong hay không \(trả về giá trị 0 : sai, 1 : đúng\)
* Hàm **int isalpha\(int ch\) **: kiểm tra ký tự ch có phải là chữ cái hay không \(trả về giá trị 0 : sai, 1 : đúng\)
* Hàm **int isdigit\(int ch\) :** kiểm tra ký tự ch có phải là chữ số hay không \(trả về giá trị 0 : sai, 1 : đúng\)

Ví dụ

> char ch = 'c';
>
> if \(!isupper\(ch\)\)
>
> > ch = toupper\(ch\);

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

