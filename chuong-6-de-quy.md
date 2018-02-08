# Chương 6: Đệ quy

## 1. Lý thuyết

Đệ quy là trong hàm có lời gọi chính hàm đó ở điều kiện nhỏ hơn. Khi viết đệ quy chú ý điều kiện dừng \(điều kiện suy biến\).

_Ví dụ_: Hàm tính giai thừa n! = 1\*2\*3\*…\*n

Các loại đệ quy:

* **Đệ qui tuyến tính**: Trong thân hàm có duy nhất một lời gọi hàm gọi lại chính nó một cách tường minh.
* **Đê qui nhị phân**: Trong thân hàm có hai một lời gọi hàm gọi lại chính nó một cách tường minh
* **Đệ qui phi tuyến**: Trong thân hàm có lời gọi hàm chính nó được đặt bên trong vòng lặp.
* **Đệ qui hỗ tương**: Trong thân hàm có lời gọi hàm tới hàm kia và trong hàm kia có lời gọi hàm tới hàm này.

Cách khử đệ quy \(nếu có\):

·Dùng mảng, dùng vòng lặp

·Truy hồi, chia để trị

·Lần ngược \(backtracking\)

## 2. Bài tập

### Bài tập 1:

Tìm ước số lẻ lớn nhất của số nguyên dương n.

Ví dụ : n = 100 thì ước lẻ lớn nhất của 100 là 25

int UocLeMax\(int n\)

{

if\(n % 2 == 1\)

 {

return n;

 }

return UocLeMax\(n/2\);

}

Hãy viết hàm đệ quy và khử đệ quy các bài toán sau đây:

### Bài tập 2:

![](file:///C:\Users\HIENLTH\AppData\Local\Temp\msohtmlclip1\01\clip_image002.png), n lần

### Bài tập 3:

Viết lại hàm Linear Search và BinarySearch dùngđệ quy.

Công thức đệ quy:

**Linear Search**:

LS\(a,n,x\) = LS\(a, n-1, x\)  nếu a\[n-1\] != x

LS\(a,n,x\) = n-1  nếu a\[n-1\] == x

LS\(a,0,x\) = -1

**Binary Search**:

BS\(a,l,r,x\) = BS\(a,l,r-1,x\)  nếu a\[mid\] &gt; x

BS\(a,l,r,x\) = BS\(a,l+1,r,x\)  nếu a\[mid\] &lt; x

BS\(a,l,r,x\) = mid  nếu a\[mid\] == x

BS\(a,l,r,x\) = -1  nếu l&gt;r

Trong đó mid = \(l + r\) / 2

### Bài tập 4:

Cho hàm![](file:///C:\Users\HIENLTH\AppData\Local\Temp\msohtmlclip1\01\clip_image004.png)

Viết hàm đệ quy và khử đệ quy.

### Bài tập 5:

Viết hàm tính phần tử thứ k của dãy Fibonaci.

![](file:///C:\Users\HIENLTH\AppData\Local\Temp\msohtmlclip1\01\clip_image006.png)

### Bài tập 6:

Viết hàm tính tổ hợp chập k của n phần tử.

![](file:///C:\Users\HIENLTH\AppData\Local\Temp\msohtmlclip1\01\clip_image008.png)

### Bài tập 7:

Bài toán tháp Hà Nội.

### Bài tập 8:

Viết hàm Ackermann’s:

![](file:///C:\Users\HIENLTH\AppData\Local\Temp\msohtmlclip1\01\clip_image010.png)
