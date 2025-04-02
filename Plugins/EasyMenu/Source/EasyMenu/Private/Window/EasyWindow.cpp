#include "Window/EasyWindow.h"

#include "EasyMenuDefine.h"


UEasyWindow* UEasyWindow::OpenWindow(TSharedPtr<SWidget> InRootWidget, FEasyWindowParameters InWindowParameters, UObject* Outer)
{
	UEasyWindow* NewWindowObject;
	if(Outer == nullptr)
	{
		NewWindowObject =  NewObject<UEasyWindow>();
	}
	else
	{
		NewWindowObject =  NewObject<UEasyWindow>(Outer);
	}
	NewWindowObject->Initialize(InRootWidget, InWindowParameters);
	return NewWindowObject;
}

void UEasyWindow::CloseWindow()
{
	UE_CLOG(
		!bIsInitialized,
		LogEasyMenu,
		Error,
		TEXT("CloseWindow() was called on OUUWindow %s that was not initialized"),
		*GetName());

	if (IsOpened())
	{
		SlateWindow->RequestDestroyWindow();
	}
	else
	{
		UE_LOG(LogEasyMenu, Warning, TEXT("CloseWindow() was called on a window that was already closed"))
	}
}

void UEasyWindow::Initialize(TSharedPtr<SWidget> InRootWidget, const FEasyWindowParameters& InWindowParameters)
{
	UE_CLOG(
		bIsInitialized,
		LogEasyMenu,
		Error,
		TEXT("Initialize() was called on OUUWindow %s that was already initialized"),
		*GetName());
	
	if (!ensure(!SlateWindow.IsValid()))
	{
		UE_LOG(
			LogEasyMenu,
			Error,
			TEXT("Initialize() was called on a UEasyWindow %s that already has a valid slate widget"),
			*GetName());
		return;
	}

	// Assign members from parameters
	RootWidget = InRootWidget;
	WindowParameters = InWindowParameters;

	// clang-format off
	SlateWindow = SNew(SWindow)
		.AutoCenter(StaticCast<EAutoCenter>((WindowParameters.AutoCenterRule)))
		.IsInitiallyMaximized(WindowParameters.bIsInitiallyMaximized)
		.ScreenPosition(WindowParameters.ScreenPosition)
		.CreateTitleBar(WindowParameters.bCreateTitleBar)
		.SizingRule(StaticCast<ESizingRule>(WindowParameters.SizingRule))
		.SupportsMaximize(WindowParameters.bSupportsMaximize)
		.SupportsMinimize(WindowParameters.bSupportsMinimize)
		.HasCloseButton(WindowParameters.bHasCloseButton)
		.Style(&FCoreStyle::Get().GetWidgetStyle<FWindowStyle>("Window"))
		.ClientSize(WindowParameters.ClientSize)
		.UseOSWindowBorder(WindowParameters.bUseOSWindowBorder)
		.Title(WindowParameters.Title);
	// clang-format on

	SlateWindow->SetOnWindowClosed(FOnWindowClosed::CreateUObject(this, &UEasyWindow::HandleSlateWindowClosed));

	SlateWindow->SetContent(RootWidget.ToSharedRef());
	FSlateApplication::Get().AddWindow(SlateWindow.ToSharedRef());
	FSlateApplication::Get().GetRenderer()->CreateViewport(SlateWindow.ToSharedRef());

	bIsInitialized = true;
}

void UEasyWindow::HandleSlateWindowClosed(const TSharedRef<SWindow>& ClosedSlateWindow)
{
	ensure(ClosedSlateWindow == SlateWindow.ToSharedRef());
	SlateWindow.Reset();
	OnWindowClosed.Broadcast(this);
}

bool UEasyWindow::IsOpened() const
{
	UE_CLOG(
		!bIsInitialized,
		LogEasyMenu,
		Error,
		TEXT("IsOpened() was called on EasyWindow %s that was not initialized"),
		*GetName());

	return SlateWindow.IsValid();
}