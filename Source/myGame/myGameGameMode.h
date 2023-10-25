// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"

// ���������һ��
#include "myGameGameMode.generated.h"


UCLASS(minimalapi)
class AmyGameGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AmyGameGameMode();

    /** �Ƴ���ǰ�˵��ؼ�������ָ���ࣨ���У����½��ؼ���*/
    UFUNCTION(BlueprintCallable, Category = "UMG Game")
    void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);

protected:
    /** ��Ϸ��ʼʱ���á�*/
    virtual void BeginPlay() override;

    /** ��Ϸ��ʼʱ�������˵��Ŀؼ��ࡣ*/
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG Game")
    TSubclassOf<UUserWidget> StartingWidgetClass;

    /** �����˵��Ŀؼ�ʵ����*/
    UPROPERTY()
    UUserWidget* CurrentWidget;
};





