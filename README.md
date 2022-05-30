# Dinogame-INT2215
# Giới thiệu:
    Họ và tên: Ngô Đăng Huy
    MSV:21020330
    Bài tập lớn : Dino-game(INT2215 -Lập trình nâng cao )
# Cài đặt game:
    1. Với người chơi game, không cần sourcode
        https://drive.google.com/file/d/1I4TD6wluYK5ECjN_517tVIlqEJyplleT/view?usp=sharing
      Ấn vào link trên tải file về, giải nén, xong đó vào thư mục, tìm file Dino_ndh.exe để chạy , và chơi.
    2. Với người cần sourcode.
        Yêu cầu:

           i) Cài đặt CodeBlocks.

           ii) Tải các thư viện hỗ trợ SDL: SDL2, SDL2_mixer, SDL2_image, SDL2_ttf.

           iii) Hướng dẫn cài đặt thư viện SDL2 vào CodeBlocks: https://youtu.be/dC77R3MYjcU?list=PL-IbDGFpCvtluDVQSSslFYzFueSbjDvZO , làm tương tự đối với các thư viện còn lại.
        Cài đặt
           i) Tải project về máy dưới dạng file ZIP hoặc dùng câu lệnh sau:
                    git clone https://github.com/ngodanghuy162/Dinogame-INT2215.git
            ii)Add headers: Mở project bằng CodeBlocks, vào Settings -> Complier -> Search directories -> Complier -> Add -> lấy đường dẫn file headers trong folder project -> OK -> OK.
            iii)Chạy chương trình: Click vào icon Build and run để chạy game.

            Nếu gặp khó khăn trong quá trình cài đặt hay chơi game, hãy liên lạc qua email ngohuy658@gmail.com.
# Mô tả game
    Đây là game Dino dựa trên game Dinosaur nổi tiếng trên google Chrome với một cải tiến về tính năng.
    Nhiệm vụ bạn là điều nút SPACE hoặc ↑ để điều khiển chú khủng long né các chướng ngại vật . Bạn có thể điều khiển khủng long để ăn ngôi sao để tăng điểm, trái tim để tăng mạng. Cứ 5 trái tim sẽ được 1 mạng, và khi chạm vào quái vật bạn sẽ bị trừ đi một mạng( hiển thị góc phải màn hình). Khi về 0 mạng, bạn sẽ thua.
    Có 3 chướng ngại vật là lửa, chim và quái vật. Quái vật sẽ xuất hiện ở level 5.
    Càng ngày , mức độ level càng cao(dựa theo điểm) , quái sẽ chạy càng nhanh, và khi đến level 5 sẽ có thêm 1 chướng ngại vật là quái vật.
    Game có menu điều khiển game,có hướng dẫn, có âm thanh và nhạc tùy bạn chọn có thể tắt bật, có chức năng tạm dừng game , ghi nhận điểm cao .
    Video demo: https://www.youtube.com/watch?v=-wS07NzBF6Y
   ![image](https://user-images.githubusercontent.com/100140595/170877452-66153a4e-4679-4afc-9f4d-a3d850831113.png)
  ![image](https://user-images.githubusercontent.com/100140595/170877550-647423a6-b1ff-45bf-928f-54ae3d24a95b.png)
 # các chức năng đã cài đặt
    Di chuyển quái vật
    Sinh vị trí quái ngẫu nhiên.
    Thêm mạng( ăn 5 trái tim 1 mạng)
    Ăn sao thêm điểm .
    (em muốn cho tọa độ mấy cái sao , trái tim lên cao một số cho đẹp nữa vì nếu chỉ để tọa độ dino nhảy lên được thì game sẽ dễ quá ạ)
    Xử lí va chạm(dino vs quái vật, dino vs sao, dino vs trái tim)
    Đọc và ghi điểm số cao nhất lên file.
    Giao diện menu dễ nhìn, tối ưu giữa các menu.
    Âm thanh nút chuột, âm thanh nhạc menu , âm thanh chơi game , âm thanh thua cuộc.
 # Các kỹ thuật sử dụng trong game
    Thư viện SDL2.0
    Kĩ thuật tách file.
    Sử dụng và quản lí mảng, xử lí đồ họa, dùng vòng lặp.
    Tạo, sử dụng và quản lí class nhiều đối tượng: địch , điểm ,hình ảnh, âm thanh,...
    Xử lí hình ảnh,  sự kiện SDL, bật/tắt âm thanh, di chuyển đối tượng, xử lí va chạm, tính toán tọa độ,....
    Có thể lưu lại điểm cao nhất sau mỗi lần chơi nhờ đọc, ghi file
    
# Nguồn tham khảo
    Các kiến thức : Youtube cô Nguyễn Thị Minh Châu
    về SDL : Lazyfoo,SDL wiki
    Hình ảnh: Google image, flaticon
    Âm thanh: Google
# Điều tâm đắc
    Dự án này hoàn toàn là do em tự làm, không đi sao chép ở bất kì đâu.
    Em thấy mình đã cải thiện được rất nhiều kỹ năng trong việc tư duy thuật toán và viết code, khả năng lên ý tưởng.
    Đa số hình ảnh game có tính độc đáo, mới lạ cho chương trình.
    Học được cách setup môi trường, sử dụng thư viện ngoài.
    Chương trình rất dễ để refactor cũng như update tính năng.
    Hiểu được cách cải tiến, clean code .
 # Điểm hạn chế
    Quản lí đối tượng chưa thật sự tối ưu.
 # Hướng phát triển tiếp
     Phát triển thêm tính quái, có đạn bắn  từ quái, dino có thể tấn công , có khiên cho dino.
     Thêm quái AI từ trên trời xuống tấn công dino.
     Cải thiện chất lượng hình ảnh.
     Bổ sung thêm quái vật Boss, dino tấn công được. Thêm quái trên trời thả đạn xuống. 
    
    
