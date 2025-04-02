#include "EMExample.h"

#include "Kismet/KismetSystemLibrary.h"
#include "Window/EasyWindow.h"


class STestDialog : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(STestDialog) {}

	/** Text to display on the "OK" button */
	SLATE_ARGUMENT(FText, OkButtonText)

	/** Tooltip text for the "OK" button */
	SLATE_ARGUMENT(FText, OkButtonTooltipText)
	
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs)
	{
		bOKPressed = false;
				
		
		ChildSlot
		[
			SNew(SVerticalBox)
			
		];
	}
	

	~STestDialog()
	{
	}

	bool bOKPressed;

};

/*void UMenuTest::Example6()
{
	TSharedPtr<STestDialog> Dialog;
	SAssignNew(Dialog, STestDialog);
	
	FEasyWindowParameters param;
	UEasyWindow* win = UEasyWindow::OpenWindow(Dialog, param, nullptr);

}*/

void UTestExample::ToolBarExample1()
{
	UKismetSystemLibrary::PrintString(GWorld, TEXT("这是一个ToolBar菜单例子，代码中搜索我"));
}

void UTestExample::ToolBarExample2(int index)
{
	UKismetSystemLibrary::PrintString(GWorld, TEXT("这是一个ToolBar菜单例子，点击了Enum: ") + FString::FromInt(index));
}

void UTestExample::ToolBarExample3(TArray<int> indexs)
{
	FString StrIndexs;
	for(int index : indexs)
	{
		StrIndexs +=  FString::FromInt(index) + ",";
	}
	UKismetSystemLibrary::PrintString(GWorld, TEXT("这是一个ToolBar菜单例子，点击了Enum: ") + StrIndexs);
}

void UMyAssetExample::Example1()
{
	UKismetSystemLibrary::PrintString(GWorld, TEXT("这是一个Asset菜单例子，代码中搜索我"));
}

void UMyActorExample::Example1()
{
	UKismetSystemLibrary::PrintString(GWorld, TEXT("这是一个Actor菜单例子，代码中搜索我"));
}


