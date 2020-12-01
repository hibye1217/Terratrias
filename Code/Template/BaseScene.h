#pragma once
#include "Scene.h"
class BaseScene :
    public Scene
{
public:


    BaseScene();
    ~BaseScene();


    // 지금 어떤 Scene이든 만들때 preparedButtonList에 button을 넣거든? 그러면 오류 날 수 있음
    // ChangeScene 쓸 때 넣고 바꿔야함.
    // 그러면 그냥 Scene에 ButtonList를 만들어두고 그걸 넘겨주는게 낫겠네. 결국 이렇게 되잖어 뭐야
    // 1. Scene에 buttonList를 만들어둔다.
    // 2. ChangeScene 할때 매개변수 scene->buttonList를 가져와서 currentButtonList에 넣는다.
    //   oldButtonList는 필요가 없어지고, 자동적으로 Scene을 파괴할때 버튼도 알아서 사라진다.
    //   Scene을 파괴하지 않으면 여러번 바꿔도 크게 상관이 없다.

    // - 해야할 것 -
    // Scene에 buttonList를 만듦
    // oldButtonLIst와 preparedButtonList를 정리
    // application에서 Scene을 파괴하고, oldButtonList를 파괴하는 것도 고치기
    // SceneManager.AppendButtonList()는 전혀 쓸모가 없어짐.
    // 만약 에러가 없다면, 주석들 모두 정리하고 md 확장자 파일 흝으면서 고친부분 수정/작성하기

    // 이 방법이 있지. esc 누르면
    // 1. 미리 준비해둔 임시메뉴 ButtonList 를 preparedButtonList에 넣는다.
    // 2. 
};

