// Fill out your copyright notice in the Description page of Project Settings.


#include "TFT_StoreComponent.h"

#include "Blueprint/UserWidget.h"
#include "TFT_Npc_store.h"
#include "TFT_StoreUI.h"
#include "TFT_Item.h"


UTFT_StoreComponent::UTFT_StoreComponent()
{

	PrimaryComponentTick.bCanEverTick = false;

	static ConstructorHelpers::FClassFinder<UUserWidget> storeWidgetClass
	(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/BluePrint/UI/TFT_StoreWidget_BP.TFT_StoreWidget_BP_C'"));
	if (storeWidgetClass.Succeeded())
	{
		_storeWidgetClass = storeWidgetClass.Class;
	}
	
	_items.SetNum(_storeMaxSize);

	static ConstructorHelpers::FClassFinder<ATFT_Item> item
	(TEXT("/Script/CoreUObject.Class'/Script/TFT_Project_A.TFT_Item'"));
	if (item.Succeeded())
	{
		_itemClass = item.Class;		
	}
}



void UTFT_StoreComponent::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(_storeWidgetClass))
	{
		_storeWidget = Cast<UTFT_StoreUI>(CreateWidget(GetWorld(), _storeWidgetClass));
	
		if (IsValid(_storeWidget))
		{
			_storeWidget->_ItemBuy.AddUObject(this, &UTFT_StoreComponent::PurchaseItem);
			_storeWidget->AddToViewport();
		}
	}

	SetStoreItem(1);
	SetStoreItem(10);
	SetStoreItem(20);

	SetStoreItem(2);


	//_item = GetWorld()->SpawnActor<ATFT_Item>(_itemClass, FVector::ZeroVector, FRotator::ZeroRotator);

	//_items[0] = _item;
}



void UTFT_StoreComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UTFT_StoreComponent::PurchaseItem(ATFT_Item* item, int32 index)
{
	auto npc = Cast<ATFT_Npc_store>(GetOwner());
	if (npc != nullptr)
	{
		npc->Interact(item);
	}
}

void UTFT_StoreComponent::SetStoreItem(int32 lineNum)
{
	/*if (_item == nullptr)
	{
		_item = GetWorld()->SpawnActor<ATFT_Item>(_itemClass, FVector::ZeroVector, FRotator::ZeroRotator);
		_item->SetItemid(lineNum);
	}

	for (int32 i = 0; i < _storeMaxSize; ++i)
	{
		if (_items.IsValidIndex(i) && _items[i] == nullptr)
		{
			_items[i] = _item;
			_storeWidget->SetStoreItem(_item, i);
			return;
		}
	}
	_item = nullptr;*/
	// 각 호출마다 새로운 아이템을 스폰
	ATFT_Item* NewItem = GetWorld()->SpawnActor<ATFT_Item>(_itemClass, FVector::ZeroVector, FRotator::ZeroRotator);

	if (NewItem)
	{
		NewItem->SetItemid(lineNum);  // 아이템 ID 설정

		for (int32 i = 0; i < _storeMaxSize; ++i)
		{
			if (_items.IsValidIndex(i) && _items[i] == nullptr)
			{
				_items[i] = NewItem;  // 배열에 새로운 아이템 저장
				_storeWidget->SetStoreItem(NewItem, i);  // UI에 아이템 추가
				NewItem->Disable();
				return;
			}
		}
	}
}

