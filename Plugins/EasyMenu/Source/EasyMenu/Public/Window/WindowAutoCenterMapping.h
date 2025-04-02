#pragma once

#include "CoreMinimal.h"
 
#include "WindowAutoCenterMapping.generated.h"

//为了可以在蓝图内使用，所以声明这个做一次转换
UENUM(BlueprintType)
enum class EWindowAutoCenterMapping : uint8
{
	None,

	PrimaryWorkArea,

	PreferredWorkArea,
};