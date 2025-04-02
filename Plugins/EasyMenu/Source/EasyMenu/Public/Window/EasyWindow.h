#pragma once

#include "CoreMinimal.h"
 
#include "Window/EasyWindowParameters.h"
#include "Widgets/SWindow.h"

#include "EasyWindow.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEasyWindowClosed, UEasyWindow*, ClosedWindow);


UCLASS(BlueprintType)
class UEasyWindow : public UObject
{
	GENERATED_BODY()
public:

	static EASYMENU_API UEasyWindow* OpenWindow(TSharedPtr<SWidget> InRootWidget, FEasyWindowParameters InWindowParameters, UObject* Outer = nullptr);

	void EASYMENU_API CloseWindow();

	FORCEINLINE FEasyWindowParameters GetWindowParameters() const { return WindowParameters; }
	
	bool EASYMENU_API IsOpened() const;

	UPROPERTY(BlueprintAssignable)
	FOnEasyWindowClosed OnWindowClosed;

	
protected:
	bool bIsInitialized = false;

	TSharedPtr<SWindow> SlateWindow;
	
	TSharedPtr<SWidget> RootWidget;

	UPROPERTY()
	FEasyWindowParameters WindowParameters;

	void Initialize(TSharedPtr<SWidget> InRootWidget, const FEasyWindowParameters& InWindowParameters);

	void HandleSlateWindowClosed(const TSharedRef<SWindow>& ClosedSlateWindow);
};
