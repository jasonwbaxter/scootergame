// Copyright 2026 Moovers Racer. All Rights Reserved.

#include "Audio/AudioManager.h"
#include "Sound/SoundBase.h"
#include "Sound/AudioComponent.h"
#include "Sound/SoundAttenuation.h"

AAudioManager::AAudioManager()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 0.016f; // 60 FPS

	// Create audio components
	EngineAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("EngineAudio"));
	MusicAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("MusicAudio"));
}

void AAudioManager::BeginPlay()
{
	Super::BeginPlay();
}

void AAudioManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAudioManager::PlayEngineSound(float RPM, float Throttle)
{
	// Play engine sound with pitch modulation based on RPM
	if (EngineAudioComponent && EngineSound)
	{
		float PitchMultiplier = FMath::Clamp(RPM / 7000.0f, 0.5f, 2.0f);
		EngineAudioComponent->SetPitchMultiplier(PitchMultiplier);

		if (!EngineAudioComponent->IsPlaying())
		{
			EngineAudioComponent->SetSound(EngineSound);
			EngineAudioComponent->Play();
		}
	}
}

void AAudioManager::StopEngineSound()
{
	if (EngineAudioComponent)
	{
		EngineAudioComponent->Stop();
	}
}

void AAudioManager::PlayClutchClick()
{
	if (EngineAudioComponent && ClutchClickSound)
	{
		EngineAudioComponent->PlaySoundAtLocation(ClutchClickSound, GetActorLocation());
	}
}

void AAudioManager::PlayExhaustPop()
{
	if (EngineAudioComponent && ExhaustPopSound)
	{
		EngineAudioComponent->PlaySoundAtLocation(ExhaustPopSound, GetActorLocation());
	}
}

void AAudioManager::PlayTurboWhine()
{
	if (EngineAudioComponent && TurboWhineSound)
	{
		EngineAudioComponent->PlaySoundAtLocation(TurboWhineSound, GetActorLocation());
	}
}

void AAudioManager::PlayRaceMusic()
{
	if (MusicAudioComponent && RaceMusic)
	{
		MusicAudioComponent->SetSound(RaceMusic);
		MusicAudioComponent->Play();
	}
}

void AAudioManager::UpdateMusicIntensity(float RaceIntensity)
{
	CurrentMusicIntensity = FMath::Clamp(RaceIntensity, 0.0f, 1.0f);

	// Modulate music volume and playback rate based on intensity
	if (MusicAudioComponent)
	{
		MusicAudioComponent->SetVolumeMultiplier(0.5f + CurrentMusicIntensity * 0.5f);
	}
}

void AAudioManager::StopMusic()
{
	if (MusicAudioComponent)
	{
		MusicAudioComponent->Stop();
	}
}
