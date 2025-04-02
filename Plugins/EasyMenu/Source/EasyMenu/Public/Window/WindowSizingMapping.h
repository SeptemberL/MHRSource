#pragma once

#include "CoreMinimal.h"
 
#include "WindowSizingMapping.generated.h"

//为了可以在蓝图内使用，所以声明这个做一次转换
UENUM(BlueprintType)
enum class EWindowSizingMapping : uint8
{
	FixedSize,

	Autosized,

	UserSized,
};