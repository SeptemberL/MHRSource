#pragma once

#include "WindowAutoCenterMapping.h"
#include "WindowSizingMapping.h"
#include "EasyWindowParameters.generated.h"
 


USTRUCT(BlueprintType)
struct FEasyWindowParameters
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EWindowAutoCenterMapping AutoCenterRule = EWindowAutoCenterMapping::PrimaryWorkArea;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsInitiallyMaximized = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D ScreenPosition = FVector2D::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCreateTitleBar = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EWindowSizingMapping SizingRule = EWindowSizingMapping::Autosized;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bSupportsMaximize = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bSupportsMinimize = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bHasCloseButton = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D ClientSize = FVector2D::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bUseOSWindowBorder = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Title = INVTEXT("");
};
