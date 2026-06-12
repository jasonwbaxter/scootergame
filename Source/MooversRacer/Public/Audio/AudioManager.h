// Copyright 2026 Moovers Racer. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AudioManager.generated.h"

class USoundAttenuation;
class USoundBase;
class UAudioComponent;

/**
 * Manages all audio including engine Foley, ambient sounds, and adaptive music.
 */
UCLASS()
class MOOVERSRACER_API AAudioManager : public AActor
{
	GENERATED_BODY()

public:
	AAudioManager();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// Engine audio
	UFUNCTION(BlueprintCallable, Category = "Audio")
	void PlayEngineSound(float RPM, float Throttle);

	UFUNCTION(BlueprintCallable, Category = "Audio")
	void StopEngineSound();

	// Foley effects
	UFUNCTION(BlueprintCallable, Category = "Audio")
	void PlayClutchClick();

	UFUNCTION(BlueprintCallable, Category = "Audio")
	void PlayExhaustPop();

	UFUNCTION(BlueprintCallable, Category = "Audio")
	void PlayTurboWhine();

	// Music
	UFUNCTION(BlueprintCallable, Category = "Audio")
	void PlayRaceMusic();

	UFUNCTION(BlueprintCallable, Category = "Audio")
	void UpdateMusicIntensity(float RaceIntensity);

	UFUNCTION(BlueprintCallable, Category = "Audio")
	void StopMusic();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAudioComponent* EngineAudioComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAudioComponent* MusicAudioComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	USoundAttenuation* AudioAttenuation;

	// Sound asset references
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	USoundBase* EngineSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	USoundBase* RaceMusic;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	USoundBase* ClutchClickSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	USoundBase* ExhaustPopSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	USoundBase* TurboWhineSound;

private:
	float CurrentMusicIntensity = 0.0f;
};
