# Module đèn cảm ứng bật tắt bằng âm thanh

## **I. Ý tưởng:**

* Tạo ra một module đèn có thể điều chỉnh được màu sắc và bật tắt bằng tiếng vỗ tay.
* Sử dụng 4095 màu cho đèn LED theo số màu RGB.
* Có thể điều chỉnh màu sắc bằng nút vặn.
* Module có thể điều khiển được tất cả các loại đèn RGB 4 chân trên thị trường.
* Giá thành rẻ, không quá 100.000 VND.
* Module có thể phân biệt được tiếng vỗ tay và tiếng ồn thông thường.

## **II. Nội dung:**

### Linh kiện (Phần cứng cần thiết)

* STM32 Blue pill/Arduino (bất kỳ loại nào)
* Potentiometer (bộ điều khiển xoay)
* 3 transistor MOSFET
* Nguồn cấp cho dải đèn LED
* Dải đèn LED
* Cảm biến âm thanh

### Mạch kết nối (Sơ đồ mạch)

_Lưu ý: Do TinkerCAD không có cảm biến âm thanh, nên trong sơ đồ này, cảm biến âm thanh được thay bằng cảm biến nhiệt độ để dễ hình dung hơn._

![diagram](https://github.com/Arcahv/IOT-Light-Clap/blob/23cd5572e47b749996298b83eb5b0954d16fb2da/Picture1.png)

## **III. Kết quả đạt được:**

* Dự án đã được thử nghiệm thành công và đáp ứng đầy đủ các yêu cầu chức năng.
* Đèn có thể bật tắt bằng tiếng vỗ tay.
* Module có thể phân biệt giữa các tiếng vỗ tay và tiếng ồn thông thường.
* Module đã được sử dụng liên tục trong 1 tuần và có tính hiệu quả cao và đáng tin cậy.
* Màu sắc của đèn được điều chỉnh chính xác và đa dạng.
* Module có thể hỗ trợ nhiều loại đèn, bao gồm cả đèn không phải RGB.

## **IV. Tương lai của dự án:**

* Dự án có thể tiếp tục phát triển và trở thành một sản phẩm IoT, kết nối với máy chủ và trở thành một thiết bị kết nối (thing).
* Module có thể được điều khiển qua các thiết bị thông minh và dễ dàng truy cập để điều chỉnh màu sắc thông qua ứng dụng.
* Dự án có thể mở rộng để điều khiển ARGB và có thêm nhiều chế độ sáng, dải màu và phổ màu rộng hơn.
