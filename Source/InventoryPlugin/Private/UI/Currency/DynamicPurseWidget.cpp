// Copyright 2022 Maximilien (Synock) Guislain


#include "UI/Currency/DynamicPurseWidget.h"

#include "Components/CoinComponent.h"
#include "UI/Currency/CurrencyWidget.h"

void UDynamicPurseWidget::InitWidget(UCoinComponent* Owner)
{
	if (PursePointer)
		PursePointer->PurseDispatcher.RemoveAll(this);

	PursePointer = Owner;
	if (PursePointer)
		PursePointer->PurseDispatcher.AddDynamic(this, &UDynamicPurseWidget::Refresh);

	CopperCurrencyWidget->SetupCoinComponent(PursePointer);
	SilverCurrencyWidget->SetupCoinComponent(PursePointer);
	GoldCurrencyWidget->SetupCoinComponent(PursePointer);
	PlatinumCurrencyWidget->SetupCoinComponent(PursePointer);

	Refresh();
}

void UDynamicPurseWidget::Refresh()
{
	CopperCurrencyWidget->UpdateCoinValue(PursePointer->GetCP());
	SilverCurrencyWidget->UpdateCoinValue(PursePointer->GetSP());
	GoldCurrencyWidget->UpdateCoinValue(PursePointer->GetGP());
	PlatinumCurrencyWidget->UpdateCoinValue(PursePointer->GetPP());
}
