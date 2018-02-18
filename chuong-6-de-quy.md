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

* Dùng mảng, dùng vòng lặp
* Truy hồi, chia để trị
* Lần ngược \(backtracking\)

## 2. Bài tập

### Bài tập 1:

Tìm ước số lẻ lớn nhất của số nguyên dương n.

Ví dụ : n = 100 thì ước lẻ lớn nhất của 100 là 25

> int UocLeMax\(int n\)
>
> {
>
> > if\(n % 2 == 1\)
> >
> > {
> >
> > > return n;
> >
> > }
> >
> > return UocLeMax\(n/2\);
>
> }

_**Hãy viết hàm đệ quy và khử đệ quy các bài toán sau đây:**_

### Bài tập 2:

![](/assets/Canban2dq.PNG)

### Bài tập 3:

Viết lại hàm **Linear Search **và** BinarySearch** dùng đệ quy.

Công thức đệ quy:

**Linear Search**:

> LS\(a,n,x\) = LS\(a, n-1, x\)  nếu a\[n-1\] != x
>
> LS\(a,n,x\) = n-1  nếu a\[n-1\] == x
>
> LS\(a,0,x\) = -1

**Binary Search**:

> BS\(a,l,r,x\) = BS\(a,l,r-1,x\)  nếu a\[mid\] &gt; x
>
> BS\(a,l,r,x\) = BS\(a,l+1,r,x\)  nếu a\[mid\] &lt; x
>
> BS\(a,l,r,x\) = mid  nếu a\[mid\] == x
>
> BS\(a,l,r,x\) = -1  nếu l&gt;r
>
> Trong đó mid = \(l + r\) / 2

### Bài tập 4:

Viết hàm đệ quy và khử đệ quy cho hàm sau:

![](/assets/bt04dq.PNG)

### Bài tập 5:

Viết hàm tính phần tử thứ k của dãy Fibonaci.

![](/assets/bt5dq.PNG)

### Bài tập 6:

Viết hàm tính tổ hợp chập k của n phần tử.

![](/assets/bt6dq.PNG)

### Bài tập 7:

Viết hàm Ackermann’s:

![](/assets/bt8dq.PNG)

### Bài tập 8:

Bài toán tháp Hà Nội.

### Bài tập 9:

Bài toán **mã đi tuần**

### Bài tập 10:

Bài toán **8 con hậu**.

