# ImageProcessor

CLI 기반 BMP 이미지 처리 프로그램입니다.  
24비트 무압축 BMP 파일을 입력받아 다양한 필터를 적용한 뒤 저장합니다.

## 개발 환경

- Windows / Visual Studio 2022
- C++17

## 빌드 방법

`ImageProcessor.sln` 파일을 Visual Studio에서 열고 빌드합니다.

## 사용법
## 필터 목록

| 필터 | 명령어 예시 | 설명 |
|------|------------|------|
| Grayscale | `--filter grayscale` | 흑백 변환 |
| 좌우 반전 | `--filter flip_horizontal` | 좌우 반전 |
| 상하 반전 | `--filter flip_vertical` | 상하 반전 |
| 이진화 | `--filter threshold:128` | 임계값 기준 흑백 변환 |
| 밝기 조절 | `--filter brightness:50` | 양수는 밝게, 음수는 어둡게 |
| 블러 | `--filter blur` | 3x3 평균 블러 |
| 히스토그램 | `--filter histogram` | 픽셀 분포 콘솔 출력 |
| 크롭 | `--filter crop:100,100,200,200` | x,y 기준 w×h 영역 잘라내기 |
| 리사이즈 | `--filter resize:256,256` | 너비×높이로 크기 변경 |

## 실행 예시

```powershell
# 흑백 변환
.\ImageProcessor.exe --input Resource\1_astronaut.bmp --output Resource\result.bmp --filter grayscale

# 좌우 반전
.\ImageProcessor.exe --input Resource\1_astronaut.bmp --output Resource\result.bmp --filter flip_horizontal

# 이진화 (임계값 128)
.\ImageProcessor.exe --input Resource\1_astronaut.bmp --output Resource\result.bmp --filter threshold:128

# 밝기 증가
.\ImageProcessor.exe --input Resource\1_astronaut.bmp --output Resource\result.bmp --filter brightness:50

# 블러
.\ImageProcessor.exe --input Resource\1_astronaut.bmp --output Resource\result.bmp --filter blur

# 크롭 (100,100 위치에서 200x200)
.\ImageProcessor.exe --input Resource\1_astronaut.bmp --output Resource\result.bmp --filter crop:100,100,200,200

# 리사이즈 (256x256)
.\ImageProcessor.exe --input Resource\1_astronaut.bmp --output Resource\result.bmp --filter resize:256,256
```