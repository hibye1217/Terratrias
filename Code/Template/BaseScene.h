#pragma once
#include "Scene.h"
class BaseScene :
    public Scene
{
public:


    BaseScene();
    ~BaseScene();


    // ���� � Scene�̵� ���鶧 preparedButtonList�� button�� �ְŵ�? �׷��� ���� �� �� ����
    // ChangeScene �� �� �ְ� �ٲ����.
    // �׷��� �׳� Scene�� ButtonList�� �����ΰ� �װ� �Ѱ��ִ°� ���ڳ�. �ᱹ �̷��� ���ݾ� ����
    // 1. Scene�� buttonList�� �����д�.
    // 2. ChangeScene �Ҷ� �Ű����� scene->buttonList�� �����ͼ� currentButtonList�� �ִ´�.
    //   oldButtonList�� �ʿ䰡 ��������, �ڵ������� Scene�� �ı��Ҷ� ��ư�� �˾Ƽ� �������.
    //   Scene�� �ı����� ������ ������ �ٲ㵵 ũ�� ����� ����.

    // - �ؾ��� �� -
    // Scene�� buttonList�� ����
    // oldButtonLIst�� preparedButtonList�� ����
    // application���� Scene�� �ı��ϰ�, oldButtonList�� �ı��ϴ� �͵� ��ġ��
    // SceneManager.AppendButtonList()�� ���� ���� ������.
    // ���� ������ ���ٸ�, �ּ��� ��� �����ϰ� md Ȯ���� ���� �y���鼭 ��ģ�κ� ����/�ۼ��ϱ�

    // �� ����� ����. esc ������
    // 1. �̸� �غ��ص� �ӽø޴� ButtonList �� preparedButtonList�� �ִ´�.
    // 2. 
};

