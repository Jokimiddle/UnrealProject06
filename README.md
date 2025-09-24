# UnrealProject06

## Unreal c++로 구현한 플랫포머게임

### 액터는 MovingPlatform, WheelObstacle, ObstacleSpawner 클래스로 구성
#### MovingPlatform: 주기적으로 두 지점을 왕복하는 플랫폼 액터. 리플렉션으로 언리얼 에디터에서 플랫폼속도, 플랫폼 최대이동거리를 변경 가능하도록 구현.
#### WheelObstacle: 가운데를 축으로하여 회전하는 장애물 액터. 생성할 때, 회전속도는 랜덤으로 타이머로 회전 갱신을 구현.
#### ObstacleSpawner: 회전장애물을 생성하는 스포너 액터. 스폰범위와 스폰 수, 랜덤으로 위치를 변경할 시간을 리플렉션으로 설정했고 스폰 위치는 랜덤으로 구현.

## 사용한 에셋
사용한 에셋 메테리얼: Stylized Windmill Valley Environment (https://fab.com/s/3ea7fe3b0876)
 