# Terratrias  
To Do:  
1. 스테이지 구현  
2. 격자 판 구현  
3. 스테이지 저장 파일 및 저장 구현  
4. 버튼 구현   
    - 버튼 리스트를 가져와서 확인  
    - 버튼 기능별로 클래스를 만들어야해서 이쁘지 않음  
        - 그렇다면 Do 부분을 다른곳에서 ref로 가져오는건 어떨까? 버튼의 기능을 N개로 분류해놓고 버튼 객체 만들때 해당하는 기능을 가져와서 내용 채우고 Do에 넘겨주는거지. <- 이거 환원주의적 발상 아니냐?  
        1. SceneChange  
        2. Scene에서 Sprite 추가/제거  
        3. 특정 값 변경  
5. 렌더 원리 파악하기  
    - 윈도우랑 관련된걸 직접 배우지 않는 이상 이해하기 어려울 것으로 예상됨  
6. Scene Change 깔끔하게 하기
    - Pade In 같은건 반투명한 판 잔뜩 깔아두고 하나씩 제거하는 방식으로 구현 가능 하다고 생각 됨.  
    - 슬라이딩 문이 닫히는건 그림만 있으면 ㄱㄴ함   
7. 경계없는 창모드 만들기  
    - https://mrhook.co.kr/m/154   
    - 상술한 내용을 참고할 것  
8. 사운드매니저 쓰는법 알아내기  
9. 전체화면 크기 찾는 방법 알아내기  
    - http://www.directxtutorial.com/Lesson.aspx?lessonid=9-4-2  
    - 성현이가 할거임  
10. 스테이지 내에서 ESC 버튼 구현  
    - ESC를 누르면, currentScene을 파괴하지 않고  subScene을 띄우고, 다시 ESC를 누르면 currentScene을 다시 불러오는 것  
    - menuScene에서 나가기 버튼 누르면 currentScene이랑 subScene 모두 파괴하고 
<br>