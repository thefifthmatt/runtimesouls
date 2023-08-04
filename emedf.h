#pragma once

#include <cstdint>

// Derived from https://github.com/AinTunez/DarkScript3/blob/master/DarkScript3/Resources/er-common.emedf.json

namespace emedf {

struct IfConditionGroup {
    static constexpr const int insBank = 0;
    static constexpr const int insId = 0;
    int8_t resultConditionGroup;
    uint8_t desiredConditionGroupState;
    int8_t targetConditionGroup;
};

struct IfParameterComparison {
    static constexpr const int insBank = 0;
    static constexpr const int insId = 1;
    int8_t resultConditionGroup;
    int8_t comparisonType;
    int32_t lefthandSide;
    int32_t righthandSide;
};

struct IfUnsignedParameterComparison {
    static constexpr const int insBank = 0;
    static constexpr const int insId = 2;
    int8_t resultConditionGroup;
    int8_t comparisonType;
    uint32_t lefthandSide;
    uint32_t righthandSide;
};

struct IfElapsedSeconds {
    static constexpr const int insBank = 1;
    static constexpr const int insId = 0;
    int8_t resultConditionGroup;
    float targetNumberOfSeconds;
};

struct IfElapsedFrames {
    static constexpr const int insBank = 1;
    static constexpr const int insId = 1;
    int8_t resultConditionGroup;
    int32_t targetNumberOfFrames;
};

struct IfRandomElapsedSeconds {
    static constexpr const int insBank = 1;
    static constexpr const int insId = 2;
    int8_t resultConditionGroup;
    float targetSecondsMin;
    float targetSecondsMax;
};

struct IfRandomElapsedFrames {
    static constexpr const int insBank = 1;
    static constexpr const int insId = 3;
    int8_t resultConditionGroup;
    int32_t targetFramesMin;
    int32_t targetFramesMax;
};

struct IfTimeOfDay {
    static constexpr const int insBank = 1;
    static constexpr const int insId = 4;
    int8_t resultConditionGroup;
    uint8_t hours;
    uint8_t minutes;
    uint8_t seconds;
};

struct IfTimeOfDayInRange {
    static constexpr const int insBank = 1;
    static constexpr const int insId = 5;
    int8_t resultConditionGroup;
    uint8_t startingHours;
    uint8_t startingMinutes;
    uint8_t startingSeconds;
    uint8_t endingHours;
    uint8_t endingMinutes;
    uint8_t endingSeconds;
};

struct IfEventFlag {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 0;
    int8_t resultConditionGroup;
    uint8_t desiredFlagState;
    uint8_t targetEventFlagType;
    uint32_t targetEventFlagId;
};

struct IfBatchEventFlags {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 1;
    int8_t resultConditionGroup;
    uint8_t desiredFlagState;
    uint8_t targetEventFlagType;
    uint32_t startingTargetEventFlagId;
    uint32_t endingTargetEventFlagId;
};

struct IfInoutsideArea {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 2;
    int8_t resultConditionGroup;
    uint8_t desiredState;
    uint32_t targetEntityId;
    uint32_t areaEntityId;
    int32_t numberOfTargetCharacters;
};

struct IfEntityInoutsideRadiusOfEntity {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 3;
    int8_t resultConditionGroup;
    uint8_t desiredState;
    uint32_t targetEntityIdA;
    uint32_t targetEntityIdB;
    float targetDistance;
    int32_t numberOfTargetCharacters;
};

struct IfPlayerHasdoesntHaveItem {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 4;
    int8_t resultConditionGroup;
    uint8_t itemType;
    int32_t itemId;
    uint8_t desiredPossessionState;
};

struct IfMultiplayerState {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 6;
    int8_t resultConditionGroup;
    int8_t desiredMultiplayerState;
};

struct IfAllPlayersInoutsideArea {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 7;
    int8_t resultConditionGroup;
    uint8_t desiredState;
    uint32_t areaEntityId;
};

struct IfPlayerInoutMap {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 8;
    int8_t resultConditionGroup;
    uint8_t shouldPlayerBeInside;
    int8_t areaId;
    int8_t blockId;
    int8_t regionId;
    int8_t indexId;
};

struct IfMultiplayerEvent {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 9;
    int8_t resultConditionGroup;
    uint32_t multiplayerEventId;
};

struct IfCountEventFlags {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 10;
    int8_t resultConditionGroup;
    uint8_t targetEventFlagType;
    uint32_t startingTargetEventFlagId;
    uint32_t endingTargetEventFlagId;
    int8_t comparisonType;
    int32_t countThreshold;
};

struct IfEventValue {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 12;
    int8_t resultConditionGroup;
    uint32_t baseEventFlagId;
    uint8_t numberOfUsedFlagBits;
    uint8_t comparisonType;
    uint32_t thresholdValue;
};

struct IfDroppedItemsInArea {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 14;
    int8_t resultConditionGroup;
    uint32_t areaEntityId;
};

struct IfDroppedItem {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 15;
    int8_t resultConditionGroup;
    uint8_t itemType;
    int32_t itemId;
};

struct IfPlayerHasdoesntHaveItemIncludingBbox {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 16;
    int8_t resultConditionGroup;
    uint8_t itemType;
    int32_t itemId;
    uint8_t desiredPossessionState;
};

struct IfGameCycle {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 17;
    int8_t resultConditionGroup;
    uint8_t comparisonType;
    uint8_t completedGameCyclesThreshold;
};

struct IfCompareEventValues {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 20;
    int8_t resultConditionGroup;
    uint32_t leftsideBaseEventFlagId;
    uint8_t leftsideNumberOfUsedFlagBits;
    uint8_t comparisonType;
    uint32_t rightsideBaseEventFlagId;
    uint8_t rightsideNumberOfUsedFlagBits;
};

struct IfOnlineMode {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 22;
    int8_t resultConditionGroup;
    uint8_t onlineMode;
};

struct IfDamageType {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 23;
    int8_t resultConditionGroup;
    uint32_t targetEntityId;
    uint32_t attackerEntityId;
    uint8_t damageType;
};

struct IfActionButtonInArea {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 24;
    int8_t resultConditionGroup;
    int32_t actionButtonParameterId;
    uint32_t targetEntityId;
};

struct IfPlayerIsInWorldType {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 26;
    int8_t resultConditionGroup;
    uint8_t worldType;
};

struct IfMapLoaded {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 30;
    int8_t resultConditionGroup;
    uint8_t areaId;
    uint8_t blockId;
    uint8_t regionId;
    uint8_t indexId;
};

struct IfWeatherActive {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 31;
    int8_t resultConditionGroup;
    int8_t weather;
    float unknown4;
    float unknown8;
};

struct IfMapHasPermissionToUpdate {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 32;
    int8_t resultConditionGroup;
    uint8_t hasPermission;
    uint8_t unknown;
    int8_t areaId;
    int8_t blockId;
    int8_t regionId;
    int8_t indexId;
};

struct IfFieldBattleBgmActive {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 33;
    int8_t resultConditionGroup;
    uint32_t npcThreatLevel;
    uint8_t isActive;
};

struct IfPlayerHasArmorEquipped {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 34;
    int8_t resultConditionGroup;
    uint8_t armorType;
    int32_t armorItemId;
    int32_t unknown;
};

struct IfCeremonyActive {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 35;
    int8_t resultConditionGroup;
    uint8_t isActive;
    int32_t ceremonyId;
};

struct IfWeatherLotActive {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 37;
    int8_t resultConditionGroup;
    int32_t weatherLotParamId;
    uint8_t isActive;
};

struct IfPlayerGender {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 38;
    int8_t resultConditionGroup;
    uint8_t gender;
};

struct IfArenaMatchReadyState {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 39;
    int8_t resultConditionGroup;
    uint8_t ready;
};

struct IfArenaSoloResults {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 40;
    int8_t resultConditionGroup;
    uint8_t result;
};

struct IfArenaSoloScoreComparison {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 41;
    int8_t resultConditionGroup;
    int8_t comparisonType;
    int32_t targetScore;
};

struct IfArenaTeamResults {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 42;
    int8_t resultConditionGroup;
    uint8_t result;
};

struct IfArenaTeamScoreComparison {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 43;
    int8_t resultConditionGroup;
    int8_t comparisonType;
    int32_t targetScore;
};

struct IfArenaMatchType {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 44;
    int8_t resultConditionGroup;
    uint8_t matchType;
    uint8_t hasSpiritSummon;
};

struct IfPlayerRespawnedInArena {
    static constexpr const int insBank = 3;
    static constexpr const int insId = 45;
    int8_t resultConditionGroup;
};

struct IfCharacterDeadalive {
    static constexpr const int insBank = 4;
    static constexpr const int insId = 0;
    int8_t resultConditionGroup;
    uint32_t targetEntityId;
    uint8_t desiredLifeState;
    int8_t comparisonType;
    float numberOfTargetCharacters;
};

struct IfCharacterHPRatio {
    static constexpr const int insBank = 4;
    static constexpr const int insId = 2;
    int8_t resultConditionGroup;
    uint32_t targetEntityId;
    int8_t comparisonType;
    float targetHPRatio;
    int8_t comparisonType2;
    float numberOfTargetCharacters;
};

struct IfCharacterType {
    static constexpr const int insBank = 4;
    static constexpr const int insId = 3;
    int8_t resultConditionGroup;
    uint32_t targetEntityId;
    int8_t targetType;
    int8_t comparisonType;
    float numberOfTargetCharacters;
};

struct IfCharacterTargetedBy {
    static constexpr const int insBank = 4;
    static constexpr const int insId = 4;
    int8_t resultConditionGroup;
    uint32_t aggressorEntityId;
    uint32_t targetEntityId;
    uint8_t shouldHave;
    int8_t comparisonType;
    float numberOfTargetCharacters;
};

struct IfCharacterHasSpEffect {
    static constexpr const int insBank = 4;
    static constexpr const int insId = 5;
    int8_t resultConditionGroup;
    uint32_t targetEntityId;
    int32_t spEffectId;
    uint8_t shouldHave;
    int8_t comparisonType;
    float numberOfTargetCharacters;
};

struct IfNPCPartHP {
    static constexpr const int insBank = 4;
    static constexpr const int insId = 6;
    int8_t resultConditionGroup;
    uint32_t targetEntityId;
    int32_t npcPartId;
    int32_t hpThreshold;
    int8_t comparisonType;
};

struct IfCharacterBackreadStatus {
    static constexpr const int insBank = 4;
    static constexpr const int insId = 7;
    int8_t resultConditionGroup;
    uint32_t targetEntityId;
    uint8_t isBackread;
    int8_t comparisonType;
    float numberOfTargetCharacters;
};

struct IfCharacterHasEventMessage {
    static constexpr const int insBank = 4;
    static constexpr const int insId = 8;
    int8_t resultConditionGroup;
    uint32_t targetEntityId;
    int32_t targetEventMessageId;
    uint8_t shouldHave;
    int8_t comparisonType;
    float numberOfTargetCharacters;
};

struct IfCharacterAIState {
    static constexpr const int insBank = 4;
    static constexpr const int insId = 9;
    int8_t resultConditionGroup;
    uint32_t targetEntityId;
    uint8_t aiState;
    int8_t comparisonType;
    float numberOfTargetCharacters;
};

struct IfPlayersClass {
    static constexpr const int insBank = 4;
    static constexpr const int insId = 11;
    int8_t resultConditionGroup;
    uint8_t classType;
};

struct IfPlayersCovenant {
    static constexpr const int insBank = 4;
    static constexpr const int insId = 12;
    int8_t resultConditionGroup;
    uint8_t covenantIndex;
};

struct IfPlayersSoulLevel {
    static constexpr const int insBank = 4;
    static constexpr const int insId = 13;
    int8_t resultConditionGroup;
    uint8_t comparisonType;
    uint32_t targetSoulLevel;
};

struct IfCharacterHPValue {
    static constexpr const int insBank = 4;
    static constexpr const int insId = 14;
    int8_t resultConditionGroup;
    uint32_t targetEntityId;
    int8_t comparisonType;
    int32_t targetHP;
    int8_t comparisonType2;
    float numberOfTargetCharacters;
};

struct IfCharacterRatioDeadalive {
    static constexpr const int insBank = 4;
    static constexpr const int insId = 15;
    int8_t resultConditionGroup;
    uint32_t targetEntityId;
    uint8_t desiredLifeState;
    int8_t comparisonType;
    float targetRatio;
};

struct IfCharacterRatioHasSpEffect {
    static constexpr const int insBank = 4;
    static constexpr const int insId = 19;
    int8_t resultConditionGroup;
    uint32_t targetEntityId;
    int32_t spEffectId;
    uint8_t shouldHave;
    int8_t comparisonType;
    float targetRatio;
};

struct IfPlayerTargeted {
    static constexpr const int insBank = 4;
    static constexpr const int insId = 28;
    int8_t resultConditionGroup;
    uint32_t minNPCThreatLevel;
    uint32_t maxNPCThreatLevel;
    uint8_t aiStateType;
};

struct IfNPCPartAttributeDamage {
    static constexpr const int insBank = 4;
    static constexpr const int insId = 30;
    int8_t resultConditionGroup;
    uint32_t targetEntityId;
    int32_t npcPartId;
    uint32_t attackerEntityId;
    uint8_t damageType;
};

struct IfCharacterInvadeType {
    static constexpr const int insBank = 4;
    static constexpr const int insId = 31;
    int8_t resultConditionGroup;
    uint32_t targetEntityId;
    uint8_t invadeTypeUnknown;
    int8_t comparisonType;
    float numberOfTargetCharacters;
};

struct IfCharacterRidingMount {
    static constexpr const int insBank = 4;
    static constexpr const int insId = 32;
    int8_t resultConditionGroup;
    uint32_t targetEntityId;
    uint8_t isMounted;
};

struct IfCharacterHasStateInfo {
    static constexpr const int insBank = 4;
    static constexpr const int insId = 34;
    int8_t resultConditionGroup;
    uint32_t targetEntityId;
    int16_t stateInfo;
    uint8_t shouldHave;
    int8_t comparisonType;
    float numberOfTargetCharacters;
};

struct IfSpecialStandbyEndedFlag {
    static constexpr const int insBank = 4;
    static constexpr const int insId = 35;
    int8_t resultConditionGroup;
    uint32_t targetEntityId;
    uint8_t desiredFlagState;
};

struct IfAssetDestroyed {
    static constexpr const int insBank = 5;
    static constexpr const int insId = 0;
    int8_t resultConditionGroup;
    uint8_t damageState;
    uint32_t targetAssetEntityId;
    int8_t comparisonType;
    float numberOfTargetAssets;
};

struct IfAssetHitBy {
    static constexpr const int insBank = 5;
    static constexpr const int insId = 1;
    int8_t resultConditionGroup;
    uint32_t targetEntityId;
    uint32_t attackerEntityId;
};

struct IfObjactEventFlag {
    static constexpr const int insBank = 5;
    static constexpr const int insId = 2;
    int8_t resultConditionGroup;
    uint32_t objactEventFlag;
};

struct IfAssetHP {
    static constexpr const int insBank = 5;
    static constexpr const int insId = 3;
    int8_t resultConditionGroup;
    uint32_t targetEntityId;
    int8_t comparisonType;
    int32_t hpThreshold;
    int8_t comparisonType2;
    float numberOfTargetAssets;
};

struct IfAssetRatioDestroyed {
    static constexpr const int insBank = 5;
    static constexpr const int insId = 6;
    int8_t resultConditionGroup;
    uint8_t damageState;
    uint32_t targetEntityId;
    int8_t comparisonType;
    float targetRatio;
};

struct IfAssetBurnState {
    static constexpr const int insBank = 5;
    static constexpr const int insId = 9;
    int8_t resultConditionGroup;
    uint32_t targetEntityId;
    uint8_t comparisonType;
    uint8_t burnStateUnknown;
    int8_t comparisonType2;
    float numberOfTargetAssets;
};

struct IfAssetBackread {
    static constexpr const int insBank = 5;
    static constexpr const int insId = 10;
    int8_t resultConditionGroup;
    uint32_t targetEntityId;
    uint8_t isBackread;
    int8_t comparisonType;
    float numberOfTargetAssets;
};

struct IfAssetRatioBackread {
    static constexpr const int insBank = 5;
    static constexpr const int insId = 11;
    int8_t resultConditionGroup;
    uint32_t targetEntityId;
    uint8_t isBackread;
    int8_t comparisonType;
    float targetRatio;
};

struct IfPlayerMovingOnHit {
    static constexpr const int insBank = 11;
    static constexpr const int insId = 0;
    int8_t resultConditionGroup;
    uint32_t hitEntityId;
};

struct IfPlayerAttackingOnHit {
    static constexpr const int insBank = 11;
    static constexpr const int insId = 1;
    int8_t resultConditionGroup;
    uint32_t hitEntityId;
};

struct IfPlayerStandingOnHit {
    static constexpr const int insBank = 11;
    static constexpr const int insId = 2;
    int8_t resultConditionGroup;
    uint32_t hitEntityId;
};

struct WaitForConditionGroupState {
    static constexpr const int insBank = 1000;
    static constexpr const int insId = 0;
    uint8_t desiredConditionGroupState;
    int8_t targetConditionGroup;
};

struct SkipIfConditionGroupStateUncompiled {
    static constexpr const int insBank = 1000;
    static constexpr const int insId = 1;
    uint8_t numberOfSkippedLines;
    uint8_t desiredConditionGroupState;
    int8_t targetConditionGroup;
};

struct EndIfConditionGroupStateUncompiled {
    static constexpr const int insBank = 1000;
    static constexpr const int insId = 2;
    uint8_t executionEndType;
    uint8_t desiredConditionGroupState;
    int8_t targetConditionGroup;
};

struct SkipUnconditionally {
    static constexpr const int insBank = 1000;
    static constexpr const int insId = 3;
    uint8_t numberOfSkippedLines;
};

struct EndUnconditionally {
    static constexpr const int insBank = 1000;
    static constexpr const int insId = 4;
    uint8_t executionEndType;
};

struct SkipIfComparison {
    static constexpr const int insBank = 1000;
    static constexpr const int insId = 5;
    uint8_t numberOfSkippedLines;
    int8_t comparisonType;
    int32_t lefthandSide;
    int32_t righthandSide;
};

struct EndIfComparison {
    static constexpr const int insBank = 1000;
    static constexpr const int insId = 6;
    uint8_t executionEndType;
    int8_t comparisonType;
    int32_t lefthandSide;
    int32_t righthandSide;
};

struct SkipIfConditionGroupStateCompiled {
    static constexpr const int insBank = 1000;
    static constexpr const int insId = 7;
    uint8_t numberOfSkippedLines;
    uint8_t desiredConditionGroupState;
    int8_t targetConditionGroup;
};

struct EndIfConditionGroupStateCompiled {
    static constexpr const int insBank = 1000;
    static constexpr const int insId = 8;
    uint8_t executionEndType;
    uint8_t desiredConditionGroupState;
    int8_t targetConditionGroup;
};

struct SkipIfUnsignedComparison {
    static constexpr const int insBank = 1000;
    static constexpr const int insId = 10;
    uint8_t numberOfSkippedLines;
    int8_t comparisonType;
    uint32_t lefthandSide;
    uint32_t righthandSide;
};

struct EndIfUnsignedComparison {
    static constexpr const int insBank = 1000;
    static constexpr const int insId = 11;
    uint8_t executionEndType;
    int8_t comparisonType;
    uint32_t lefthandSide;
    uint32_t righthandSide;
};

struct GotoIfConditionGroupStateUncompiled {
    static constexpr const int insBank = 1000;
    static constexpr const int insId = 101;
    uint8_t label;
    uint8_t desiredConditionGroupState;
    int8_t targetConditionGroup;
};

struct GotoUnconditionally {
    static constexpr const int insBank = 1000;
    static constexpr const int insId = 103;
    uint8_t label;
};

struct GotoIfComparison {
    static constexpr const int insBank = 1000;
    static constexpr const int insId = 105;
    uint8_t label;
    int8_t comparisonType;
    int32_t lefthandSide;
    int32_t righthandSide;
};

struct GotoIfConditionGroupStateCompiled {
    static constexpr const int insBank = 1000;
    static constexpr const int insId = 107;
    uint8_t label;
    uint8_t desiredConditionGroupState;
    int8_t targetConditionGroup;
};

struct GotoIfUnsignedComparison {
    static constexpr const int insBank = 1000;
    static constexpr const int insId = 108;
    uint8_t label;
    int8_t comparisonType;
    uint32_t lefthandSide;
    uint32_t righthandSide;
};

struct WaitFixedTimeSeconds {
    static constexpr const int insBank = 1001;
    static constexpr const int insId = 0;
    float numberOfSeconds;
};

struct WaitFixedTimeFrames {
    static constexpr const int insBank = 1001;
    static constexpr const int insId = 1;
    int32_t numberOfFrames;
};

struct WaitRandomTimeSeconds {
    static constexpr const int insBank = 1001;
    static constexpr const int insId = 2;
    float minNumberOfSeconds;
    float maxNumberOfSeconds;
};

struct WaitRandomTimeFrames {
    static constexpr const int insBank = 1001;
    static constexpr const int insId = 3;
    int32_t minNumberOfFrames;
    int32_t maxNumberOfFrames;
};

struct WaitUntilTimeOfDayInRange {
    static constexpr const int insBank = 1001;
    static constexpr const int insId = 5;
    uint8_t startingHours;
    uint8_t startingMinutes;
    uint8_t startingSeconds;
    uint8_t endingHours;
    uint8_t endingMinutes;
    uint8_t endingSeconds;
};

struct WaitFixedTimeRealFrames {
    static constexpr const int insBank = 1001;
    static constexpr const int insId = 6;
    int32_t numberOfFrames;
};

struct WaitUntilArenaHalfTime {
    static constexpr const int insBank = 1001;
    static constexpr const int insId = 8;
    uint8_t matchType;
    uint8_t isSecondHalf;
};

struct WaitForEventFlag {
    static constexpr const int insBank = 1003;
    static constexpr const int insId = 0;
    uint8_t desiredFlagState;
    uint8_t targetEventFlagType;
    uint32_t targetEventFlagId;
};

struct SkipIfEventFlag {
    static constexpr const int insBank = 1003;
    static constexpr const int insId = 1;
    uint8_t numberOfSkippedLines;
    uint8_t desiredFlagState;
    uint8_t targetEventFlagType;
    uint32_t targetEventFlagId;
};

struct EndIfEventFlag {
    static constexpr const int insBank = 1003;
    static constexpr const int insId = 2;
    uint8_t executionEndType;
    uint8_t desiredFlagState;
    uint8_t targetEventFlagType;
    uint32_t targetEventFlagId;
};

struct SkipIfBatchEventFlags {
    static constexpr const int insBank = 1003;
    static constexpr const int insId = 3;
    uint8_t numberOfSkippedLines;
    uint8_t desiredFlagState;
    uint8_t targetEventFlagType;
    uint32_t startingTargetEventFlagId;
    uint32_t endingTargetEventFlagId;
};

struct EndIfBatchEventFlags {
    static constexpr const int insBank = 1003;
    static constexpr const int insId = 4;
    uint8_t executionEndType;
    uint8_t desiredFlagState;
    uint8_t targetEventFlagType;
    uint32_t startingTargetEventFlagId;
    uint32_t endingTargetEventFlagId;
};

struct SkipIfMultiplayerState {
    static constexpr const int insBank = 1003;
    static constexpr const int insId = 5;
    uint8_t numberOfSkippedLines;
    int8_t desiredMultiplayerState;
};

struct EndIfMultiplayerState {
    static constexpr const int insBank = 1003;
    static constexpr const int insId = 6;
    uint8_t executionEndType;
    int8_t desiredMultiplayerState;
};

struct SkipIfPlayerInoutMap {
    static constexpr const int insBank = 1003;
    static constexpr const int insId = 7;
    uint8_t numberOfSkippedLines;
    uint8_t shouldPlayerBeInside;
    int8_t areaId;
    int8_t blockId;
    int8_t regionId;
    int8_t indexId;
};

struct EndIfPlayerInoutMap {
    static constexpr const int insBank = 1003;
    static constexpr const int insId = 8;
    uint8_t executionEndType;
    uint8_t shouldPlayerBeInside;
    int8_t areaId;
    int8_t blockId;
    int8_t regionId;
    int8_t indexId;
};

struct SkipIfNumberOfCoopClients {
    static constexpr const int insBank = 1003;
    static constexpr const int insId = 9;
    uint8_t numberOfSkippedLines;
    uint8_t comparisonType;
    uint8_t targetNumberOfClients;
};

struct EndIfNumberOfCoopClients {
    static constexpr const int insBank = 1003;
    static constexpr const int insId = 10;
    uint8_t executionEndType;
    uint8_t comparisonType;
    uint8_t targetNumberOfClients;
};

struct SkipIfPlayerIsInWorldType {
    static constexpr const int insBank = 1003;
    static constexpr const int insId = 12;
    uint8_t numberOfSkippedLines;
    uint8_t worldType;
};

struct GotoIfPlayerIsInWorldType {
    static constexpr const int insBank = 1003;
    static constexpr const int insId = 13;
    uint8_t label;
    uint8_t worldType;
};

struct EndIfPlayerIsInWorldType {
    static constexpr const int insBank = 1003;
    static constexpr const int insId = 14;
    uint8_t executionEndType;
    uint8_t worldType;
};

struct GotoIfEventFlag {
    static constexpr const int insBank = 1003;
    static constexpr const int insId = 101;
    uint8_t label;
    uint8_t desiredFlagState;
    uint8_t targetEventFlagType;
    uint32_t targetEventFlagId;
};

struct GotoIfBatchEventFlags {
    static constexpr const int insBank = 1003;
    static constexpr const int insId = 103;
    uint8_t label;
    uint8_t desiredFlagState;
    uint8_t targetEventFlagType;
    uint32_t startingTargetEventFlagId;
    uint32_t endingTargetEventFlagId;
};

struct GotoIfMultiplayerState {
    static constexpr const int insBank = 1003;
    static constexpr const int insId = 105;
    uint8_t label;
    int8_t desiredMultiplayerState;
};

struct GotoIfPlayerInoutMap {
    static constexpr const int insBank = 1003;
    static constexpr const int insId = 107;
    uint8_t label;
    uint8_t shouldPlayerBeInside;
    int8_t areaId;
    int8_t blockId;
    int8_t regionId;
    int8_t indexId;
};

struct GotoIfNumberOfCoopClients {
    static constexpr const int insBank = 1003;
    static constexpr const int insId = 109;
    uint8_t label;
    uint8_t comparisonType;
    uint8_t targetNumberOfClients;
};

struct GotoIfInoutsideArea {
    static constexpr const int insBank = 1003;
    static constexpr const int insId = 200;
    uint8_t label;
    uint8_t desiredState;
    uint32_t targetEntityId;
    uint32_t areaEntityId;
    int32_t numberOfTargetCharacters;
};

struct EndIfInoutsideArea {
    static constexpr const int insBank = 1003;
    static constexpr const int insId = 201;
    uint8_t executionEndType;
    uint8_t desiredState;
    uint32_t targetEntityId;
    uint32_t areaEntityId;
    int32_t numberOfTargetCharacters;
};

struct SkipIfInoutsideArea {
    static constexpr const int insBank = 1003;
    static constexpr const int insId = 202;
    uint8_t numberOfSkippedLines;
    uint8_t desiredState;
    uint32_t targetEntityId;
    uint32_t areaEntityId;
    int32_t numberOfTargetCharacters;
};

struct SkipIfMapHasPermissionToUpdate {
    static constexpr const int insBank = 1003;
    static constexpr const int insId = 203;
    uint8_t numberOfSkippedLines;
    uint8_t hasPermission;
    uint8_t unknown;
    int8_t areaId;
    int8_t blockId;
    int8_t regionId;
    int8_t indexId;
};

struct GotoIfMapHasPermissionToUpdate {
    static constexpr const int insBank = 1003;
    static constexpr const int insId = 204;
    uint8_t label;
    uint8_t hasPermission;
    uint8_t unknown;
    int8_t areaId;
    int8_t blockId;
    int8_t regionId;
    int8_t indexId;
};

struct EndIfMapHasPermissionToUpdate {
    static constexpr const int insBank = 1003;
    static constexpr const int insId = 205;
    uint8_t executionEndType;
    uint8_t hasPermission;
    uint8_t unknown;
    int8_t areaId;
    int8_t blockId;
    int8_t regionId;
    int8_t indexId;
};

struct SkipIfCeremonyActive {
    static constexpr const int insBank = 1003;
    static constexpr const int insId = 206;
    uint8_t numberOfSkippedLines;
    uint8_t isActive;
    int32_t ceremonyId;
};

struct GotoIfCeremonyActive {
    static constexpr const int insBank = 1003;
    static constexpr const int insId = 207;
    uint8_t label;
    uint8_t isActive;
    int32_t ceremonyId;
};

struct EndIfCeremonyActive {
    static constexpr const int insBank = 1003;
    static constexpr const int insId = 208;
    uint8_t executionEndType;
    uint8_t isActive;
    int32_t ceremonyId;
};

struct SkipIfArenaMatchType {
    static constexpr const int insBank = 1003;
    static constexpr const int insId = 212;
    uint8_t numberOfSkippedLines;
    uint8_t matchType;
    uint8_t hasSpiritSummon;
};

struct GotoIfArenaMatchType {
    static constexpr const int insBank = 1003;
    static constexpr const int insId = 213;
    uint8_t label;
    uint8_t matchType;
    uint8_t hasSpiritSummon;
};

struct EndIfArenaMatchType {
    static constexpr const int insBank = 1003;
    static constexpr const int insId = 214;
    uint8_t executionEndType;
    uint8_t matchType;
    uint8_t hasSpiritSummon;
};

struct SkipIfCharacterHasSpEffect {
    static constexpr const int insBank = 1004;
    static constexpr const int insId = 0;
    uint8_t numberOfSkippedLines;
    uint32_t targetEntityId;
    int32_t spEffectId;
    uint8_t shouldHave;
    int8_t comparisonType;
    int32_t numberOfTargetCharacters;
};

struct GotoIfCharacterHasSpEffect {
    static constexpr const int insBank = 1004;
    static constexpr const int insId = 1;
    uint8_t label;
    uint32_t targetEntityId;
    int32_t spEffectId;
    uint8_t shouldHave;
    int8_t comparisonType;
    int32_t numberOfTargetCharacters;
};

struct EndIfCharacterHasSpEffect {
    static constexpr const int insBank = 1004;
    static constexpr const int insId = 2;
    uint8_t executionEndType;
    uint32_t targetEntityId;
    int32_t spEffectId;
    uint8_t shouldHave;
    int8_t comparisonType;
    int32_t numberOfTargetCharacters;
};

struct SkipIfSpecialStandbyEndedFlag {
    static constexpr const int insBank = 1004;
    static constexpr const int insId = 3;
    uint8_t numberOfSkippedLines;
    uint32_t targetEntityId;
    uint8_t desiredFlagState;
};

struct GotoIfSpecialStandbyEndedFlag {
    static constexpr const int insBank = 1004;
    static constexpr const int insId = 4;
    uint8_t label;
    uint32_t targetEntityId;
    uint8_t desiredFlagState;
};

struct EndIfSpecialStandbyEndedFlag {
    static constexpr const int insBank = 1004;
    static constexpr const int insId = 5;
    uint8_t executionEndType;
    uint32_t targetEntityId;
    uint8_t desiredFlagState;
};

struct WaitForAssetDestroyed {
    static constexpr const int insBank = 1005;
    static constexpr const int insId = 0;
    uint8_t damageState;
    uint32_t targetAssetEntityId;
    int8_t comparisonType;
    float numberOfTargetAssets;
};

struct SkipIfAssetDestroyed {
    static constexpr const int insBank = 1005;
    static constexpr const int insId = 1;
    uint8_t numberOfSkippedLines;
    uint8_t damageState;
    uint32_t targetAssetEntityId;
    int8_t comparisonType;
    float numberOfTargetAssets;
};

struct EndIfAssetDestroyed {
    static constexpr const int insBank = 1005;
    static constexpr const int insId = 2;
    uint8_t executionEndType;
    uint8_t damageState;
    uint32_t targetAssetEntityId;
    int8_t comparisonType;
    float numberOfTargetAssets;
};

struct GotoIfAssetDestroyed {
    static constexpr const int insBank = 1005;
    static constexpr const int insId = 101;
    uint8_t label;
    uint8_t damageState;
    uint32_t targetAssetEntityId;
    int8_t comparisonType;
    float numberOfTargetAssets;
};

struct Label0 {
    static constexpr const int insBank = 1014;
    static constexpr const int insId = 0;
};

struct Label1 {
    static constexpr const int insBank = 1014;
    static constexpr const int insId = 1;
};

struct Label2 {
    static constexpr const int insBank = 1014;
    static constexpr const int insId = 2;
};

struct Label3 {
    static constexpr const int insBank = 1014;
    static constexpr const int insId = 3;
};

struct Label4 {
    static constexpr const int insBank = 1014;
    static constexpr const int insId = 4;
};

struct Label5 {
    static constexpr const int insBank = 1014;
    static constexpr const int insId = 5;
};

struct Label6 {
    static constexpr const int insBank = 1014;
    static constexpr const int insId = 6;
};

struct Label7 {
    static constexpr const int insBank = 1014;
    static constexpr const int insId = 7;
};

struct Label8 {
    static constexpr const int insBank = 1014;
    static constexpr const int insId = 8;
};

struct Label9 {
    static constexpr const int insBank = 1014;
    static constexpr const int insId = 9;
};

struct Label10 {
    static constexpr const int insBank = 1014;
    static constexpr const int insId = 10;
};

struct Label11 {
    static constexpr const int insBank = 1014;
    static constexpr const int insId = 11;
};

struct Label12 {
    static constexpr const int insBank = 1014;
    static constexpr const int insId = 12;
};

struct Label13 {
    static constexpr const int insBank = 1014;
    static constexpr const int insId = 13;
};

struct Label14 {
    static constexpr const int insBank = 1014;
    static constexpr const int insId = 14;
};

struct Label15 {
    static constexpr const int insBank = 1014;
    static constexpr const int insId = 15;
};

struct Label16 {
    static constexpr const int insBank = 1014;
    static constexpr const int insId = 16;
};

struct Label17 {
    static constexpr const int insBank = 1014;
    static constexpr const int insId = 17;
};

struct Label18 {
    static constexpr const int insBank = 1014;
    static constexpr const int insId = 18;
};

struct Label19 {
    static constexpr const int insBank = 1014;
    static constexpr const int insId = 19;
};

struct Label20 {
    static constexpr const int insBank = 1014;
    static constexpr const int insId = 20;
};

struct InitializeEvent {
    static constexpr const int insBank = 2000;
    static constexpr const int insId = 0;
    int32_t eventSlotId;
    uint32_t eventId;
    uint32_t parameters;
};

struct SetNetworkSyncState {
    static constexpr const int insBank = 2000;
    static constexpr const int insId = 2;
    uint8_t disabledenabled;
};

struct ClearCompiledConditionGroupState {
    static constexpr const int insBank = 2000;
    static constexpr const int insId = 3;
    uint8_t dummy;
};

struct SaveRequest {
    static constexpr const int insBank = 2000;
    static constexpr const int insId = 5;
    uint8_t dummy;
};

struct InitializeCommonEvent {
    static constexpr const int insBank = 2000;
    static constexpr const int insId = 6;
    int32_t unknown;
    uint32_t eventId;
    uint32_t parameters;
};

struct StartPs5Activity {
    static constexpr const int insBank = 2000;
    static constexpr const int insId = 7;
    int32_t activityId;
};

struct EndPs5Activity {
    static constexpr const int insBank = 2000;
    static constexpr const int insId = 8;
    int32_t activityId;
};

struct SetCurrentTime {
    static constexpr const int insBank = 2001;
    static constexpr const int insId = 4;
    uint8_t hours;
    uint8_t minutes;
    uint8_t seconds;
    uint8_t fadeTransition;
    uint8_t shouldWaitForCompletion;
    uint8_t showClock;
    float clockStartupDelayS;
    float clockMoveTimeS;
    float clockFinishDelayS;
};

struct FreezeTime {
    static constexpr const int insBank = 2001;
    static constexpr const int insId = 5;
    uint8_t shouldFreeze;
};

struct PlayCutsceneToAll {
    static constexpr const int insBank = 2002;
    static constexpr const int insId = 1;
    int32_t cutsceneId;
    uint32_t playbackMethod;
};

struct PlayCutsceneToPlayer {
    static constexpr const int insBank = 2002;
    static constexpr const int insId = 3;
    int32_t cutsceneId;
    uint32_t playbackMethod;
    uint32_t playerEntityId;
};

struct PlayCutsceneToPlayerUnknown200204 {
    static constexpr const int insBank = 2002;
    static constexpr const int insId = 4;
    int32_t cutsceneId;
    uint32_t playbackMethod;
    uint32_t areaEntityId;
    int32_t unknownc;
    uint32_t playerEntityId;
    int32_t unknown14;
};

struct PlayCutsceneToPlayerUnknown200209 {
    static constexpr const int insBank = 2002;
    static constexpr const int insId = 9;
    int32_t cutsceneId;
    uint32_t playbackMethod;
    int32_t unknown8;
    int32_t unknownc;
    uint32_t playerEntityId;
    int32_t unknown14;
    uint8_t unknown18;
    uint8_t unknown19;
    float unknown1c;
    uint8_t unknown20;
    uint8_t unknown21;
    uint8_t unknown22;
    uint8_t unknown23;
};

struct PlayCutsceneToPlayerWithWeatherAndTime {
    static constexpr const int insBank = 2002;
    static constexpr const int insId = 10;
    int32_t cutsceneId;
    uint32_t playbackMethod;
    uint32_t playerEntityId;
    uint8_t shouldChangeWeather;
    int8_t weather;
    float weatherLifespanSeconds;
    uint8_t shouldChangeTime;
    uint8_t hours;
    uint8_t minutes;
    uint8_t seconds;
};

struct PlayCutsceneToPlayerAndWarp {
    static constexpr const int insBank = 2002;
    static constexpr const int insId = 11;
    int32_t cutsceneId;
    uint32_t playbackMethod;
    uint32_t areaEntityId;
    int32_t mapId;
    uint32_t playerEntityId;
    int32_t unknown14;
    uint8_t unknown18;
};

struct PlayCutsceneToPlayerAndWarpWithWeatherAndTime {
    static constexpr const int insBank = 2002;
    static constexpr const int insId = 12;
    int32_t cutsceneId;
    uint32_t playbackMethod;
    uint32_t areaEntityId;
    int32_t mapId;
    uint32_t playerEntityId;
    int32_t unknown14;
    uint8_t unknown18;
    uint8_t shouldChangeWeather;
    int8_t weather;
    float weatherLifespanSeconds;
    uint8_t shouldChangeTime;
    uint8_t hours;
    uint8_t minutes;
    uint8_t seconds;
};

struct PlayCutsceneToPlayerAndWarpWithStablePositionUpdate {
    static constexpr const int insBank = 2002;
    static constexpr const int insId = 13;
    int32_t cutsceneId;
    uint32_t playbackMethod;
    uint32_t areaEntityId;
    int32_t mapId;
    uint32_t playerEntityId;
    int32_t unknown14;
    uint8_t unknown18;
    uint8_t shouldUpdateStablePosition;
};

struct SetGeneratorState {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 3;
    uint32_t generatorEntityId;
    uint8_t disabledenabled;
};

struct AwardItemLot {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 4;
    int32_t itemLotId;
};

struct ShootBullet {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 5;
    uint32_t bulletTeamEntityId;
    uint32_t bulletProducerEntityId;
    int32_t dummypolyId;
    int32_t behaviorId;
    int32_t firingAngleX;
    int32_t firingAngleY;
    int32_t firingAngleZ;
};

struct ChangeMapHitEnableState {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 6;
    uint32_t entityId;
    uint8_t disabledenabled;
};

struct SetMapVisibility {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 7;
    uint32_t entityId;
    uint8_t disabledenabled;
};

struct SetEventState {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 8;
    uint32_t eventId;
    int32_t eventSlotId;
    uint8_t eventState;
};

struct InvertEventFlag {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 9;
    uint32_t eventFlagId;
};

struct DisplayBossHealthBar {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 11;
    int8_t disabledenabled;
    uint32_t entityId;
    int16_t slotNumber;
    int32_t nameId;
};

struct HandleBossDefeatAndDisplayBanner {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 12;
    uint32_t entityId;
    uint8_t bannerType;
};

struct ModifyNavimeshConnectionBitflag {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 13;
    uint32_t navimeshEntityId;
    uint32_t navimeshType;
    uint8_t typeBitOperation;
};

struct WarpPlayer {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 14;
    uint8_t areaId;
    uint8_t blockId;
    uint8_t regionId;
    uint8_t indexId;
    uint32_t initialAreaEntityId;
    int32_t subareaNamePopupMessageId;
};

struct HandleMinibossDefeat {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 15;
    uint32_t entityId;
};

struct TriggerMultiplayerEvent {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 16;
    uint32_t multiplayerEventId;
};

struct RandomlySetEventFlagInRange {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 17;
    uint32_t eventFlagIdMin;
    uint32_t eventFlagIdMax;
    uint8_t flagState;
};

struct ForceAnimationPlayback {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 18;
    uint32_t entityId;
    int32_t animationId;
    uint8_t shouldLoop;
    uint8_t shouldWaitForCompletion;
    uint8_t ignoreWaitForTransition;
    int8_t comparisonType;
    float numberOfTargetCharacters;
};

struct IncrementGameCycle {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 21;
    uint8_t dummy;
};

struct BatchSetEventFlags {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 22;
    uint32_t eventFlagIdStart;
    uint32_t eventFlagIdEnd;
    uint8_t flagState;
};

struct SetPlayerRespawnPoint {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 23;
    uint32_t respawnAreaEntityId;
};

struct RemoveItemFromPlayer {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 24;
    uint8_t itemType;
    int32_t itemId;
    int32_t number;
};

struct PlaceNPCSummonSign {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 25;
    int32_t signType;
    uint32_t summonedNPCEntityId;
    uint32_t spawnAreaEntityId;
    uint32_t summonEventFlagId;
    uint32_t dismissalEventFlagId;
    uint8_t unknown;
};

struct SetVisibilityOfMessage {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 26;
    uint32_t messageEntityId;
    uint8_t disabledenabled;
};

struct AwardAchievement {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 28;
    int32_t achievementId;
};

struct IncrementEventValue {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 31;
    uint32_t baseEventFlagId;
    uint32_t numberOfUsedFlagBits;
    uint32_t maximumAllowedValue;
};

struct ClearEventValue {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 32;
    uint32_t baseEventFlagId;
    uint32_t numberOfUsedFlagBits;
};

struct SetSnugglyNextTrade {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 33;
    uint32_t eventFlagId;
};

struct SpawnSnugglyItem {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 34;
    int32_t itemLotId;
    uint32_t placementAreaEntityId;
    uint32_t eventFlagId;
    uint32_t hitEntityId;
};

struct MoveBloodstainAndDroppedItems {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 35;
    uint32_t sourceAreaEntityId;
    uint32_t destinationAreaEntityId;
};

struct AwardItemsIncludingClients {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 36;
    int32_t itemLotId;
};

struct EventValueOperation {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 41;
    uint32_t baseEventFlagId;
    uint32_t numberOfUsedFlagBits;
    int32_t operand;
    uint32_t baseEventFlagIdOperand;
    uint32_t numberOfUsedEventFlagBitsOperand;
    int8_t calculationType;
};

struct StoreItemAmountHeldInEventValue {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 42;
    uint8_t itemType;
    int32_t itemId;
    uint32_t baseEventFlagId;
    uint32_t numberOfUsedFlagBits;
};

struct DirectlyGivePlayerItem {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 43;
    uint8_t itemType;
    int32_t itemId;
    uint32_t baseEventFlagId;
    uint32_t numberOfUsedFlagBits;
};

struct ToggleDirectionDisplay {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 44;
    uint8_t disabledenabled;
};

struct TriggerAisound {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 52;
    int32_t aiSoundParamId;
    uint32_t entityId;
    uint8_t originEntityType;
};

struct InvokeEnemyGenerator {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 54;
    uint32_t generatorEntityId;
};

struct BatchSetNetworkconnectedEventFlags {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 63;
    uint32_t eventFlagIdStart;
    uint32_t eventFlagIdEnd;
    uint8_t flagState;
};

struct SetOmissionModeCounts {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 64;
    int32_t level1Count;
    int32_t level2Count;
};

struct ResetOmissionModeCountsToDefault {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 65;
};

struct SetEventFlag {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 66;
    uint8_t targetEventFlagType;
    uint32_t targetEventFlagId;
    uint8_t desiredFlagState;
};

struct ChangeWeather {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 68;
    int8_t weather;
    float lifespanSeconds;
    uint8_t shouldSwitchImmediately;
};

struct SetNetworkconnectedEventFlag {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 69;
    uint8_t targetEventFlagType;
    uint32_t targetEventFlagId;
    uint8_t desiredFlagState;
};

struct TriggerAreaReload {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 70;
    uint8_t ignoreIsMyWorldCheck;
};

struct AwardGesture {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 71;
    int32_t gestureParamId;
};

struct ReduceBloodstainSouls {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 72;
    float decreaseRate;
    int32_t soulAmountSaveSlotId;
};

struct IncreaseEnemySoulDropAmount {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 73;
    uint32_t entityId;
    int32_t fixedIncreaseAmount;
    int32_t soulAmountLoadSlotId;
};

struct IssueEndOfPseudoMultiplayerNotification {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 74;
    uint8_t success;
};

struct UseFarviewCamera {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 75;
    uint32_t farviewId;
    uint32_t assetEntityId;
    int32_t dummypolyId;
};

struct SetPlayerPositionDisplay {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 76;
    uint8_t state;
    uint8_t aboveground;
    uint8_t areaId;
    uint8_t blockId;
    uint8_t regionId;
    uint8_t indexId;
    float x;
    float y;
    float z;
};

struct SetPsuedoMultiplayerReturnPosition {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 77;
    uint32_t areaEntityId;
};

struct OpenWorldMapPoint {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 78;
    int32_t worldMapPointParamId;
    float distance;
};

struct SendNPCSummonHome {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 79;
    uint32_t npcEntityId;
};

struct ShowTextOnLoadingScreen {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 80;
    uint8_t state;
};

struct RemoveGesture {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 81;
    int32_t gestureParamId;
};

struct DeleteNPCSummonSign {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 82;
    uint32_t npcEntityId;
};

struct Unknown200383 {
    static constexpr const int insBank = 2003;
    static constexpr const int insId = 83;
    uint8_t unknown;
};

struct SetCharacterAIState {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 1;
    uint32_t entityId;
    uint8_t disabledenabled;
};

struct SetCharacterTeamType {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 2;
    uint32_t entityId;
    uint8_t teamType;
};

struct ForceCharacterDeath {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 4;
    uint32_t entityId;
    uint8_t shouldReceiveRunes;
};

struct ChangeCharacterEnableState {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 5;
    uint32_t characterEntityId;
    uint8_t disabledenabled;
};

struct EzstateInstructionRequest {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 6;
    uint32_t entityId;
    int32_t command;
    uint8_t slot;
};

struct CreateBulletOwner {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 7;
    uint32_t entityId;
};

struct SetSpEffect {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 8;
    uint32_t entityId;
    int32_t spEffectId;
};

struct SetCharacterGravity {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 10;
    uint32_t entityId;
    uint8_t disabledenabled;
};

struct SetCharacterEventTarget {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 11;
    uint32_t entityId;
    uint32_t entityId2;
};

struct SetCharacterImmortality {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 12;
    uint32_t entityId;
    uint8_t disabledenabled;
};

struct SetCharacterHome {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 13;
    uint32_t entityId;
    uint32_t areaEntityId;
};

struct RotateCharacter {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 14;
    uint32_t entityId;
    uint32_t relativeEntityId;
    int32_t playAnimationId;
    uint8_t shouldWaitForCompletion;
};

struct SetCharacterInvincibility {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 15;
    uint32_t entityId;
    uint8_t disabledenabled;
};

struct ClearCharactersAITarget {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 16;
    uint32_t entityId;
};

struct RequestCharacterAICommand {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 17;
    uint32_t entityId;
    int32_t commandId;
    uint8_t slotNumber;
};

struct SetEventPoint {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 18;
    uint32_t entityId;
    uint32_t relativeEntityId;
    float reactionDistance;
};

struct SetCharacterAIId {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 19;
    uint32_t entityId;
    int32_t aiId;
};

struct RequestCharacterAIReplan {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 20;
    uint32_t entityId;
};

struct ClearSpEffect {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 21;
    uint32_t entityId;
    int32_t spEffectId;
};

struct CreateNPCPart {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 22;
    uint32_t entityId;
    int16_t npcPartId;
    int16_t npcPartGroupIdx;
    int32_t npcPartHP;
    float damageCorrection;
    float bodyDamageCompensation;
    uint8_t isInvincible;
    uint8_t startInStoppedState;
};

struct SetNPCPartHP {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 23;
    uint32_t entityId;
    int32_t npcPartId;
    int32_t desiredHP;
    uint8_t shouldAllowHPAboveMaxHP;
};

struct SetNPCPartSEAndSFX {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 24;
    uint32_t entityId;
    int32_t npcPartId;
    int32_t defenseMaterialSEId;
    int32_t defenseMaterialSFXId;
    int32_t unknowna;
    int32_t unknownb;
    int32_t unknownc;
};

struct SetNPCPartBulletDamageMultiplier {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 25;
    uint32_t entityId;
    int32_t npcPartId;
    float bulletDamageMultiplier;
};

struct ChangeCharacterDispmask {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 26;
    uint32_t entityId;
    uint8_t bitNumber;
    uint8_t switchType;
};

struct ChangeCharacterHitmask {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 27;
    uint32_t characterEntityId;
    uint8_t bitNumber;
    uint8_t switchType;
};

struct SetNetworkUpdateAuthority {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 28;
    uint32_t entityId;
    int32_t authorityLevel;
};

struct SetCharacterBackreadState {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 29;
    uint32_t entityId;
    uint8_t removed;
};

struct SetCharacterHPBarDisplay {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 30;
    uint32_t entityId;
    uint8_t disabledenabled;
};

struct SetCharacterMaphit {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 31;
    uint32_t entityId;
    uint8_t disabled;
};

struct CreateReferredDamagePair {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 33;
    uint32_t sourceEntityId;
    uint32_t targetEntityId;
};

struct SetNetworkUpdateRate {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 34;
    uint32_t entityId;
    uint8_t useFixedFrequency;
    int8_t updateFrequency;
};

struct SetCharacterDefaultBackreadState {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 35;
    uint32_t entityId;
    uint8_t disabledenabled;
};

struct ForceCharacterTreasure {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 37;
    uint32_t characterEntityId;
};

struct BetrayCharactersCurrentCovenant {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 38;
    uint8_t dummy;
};

struct ChangeCharacterCollisionState {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 39;
    uint32_t entityId;
    uint8_t disabledenabled;
};

struct WarpCharacterAndSetFloor {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 40;
    uint32_t entityId;
    uint8_t warpType;
    uint32_t warpDestinationEntityId;
    int32_t dummypolyId;
    uint32_t warpDestinationHitEntityId;
};

struct IssueShortWarpRequest {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 41;
    uint32_t entityId;
    uint8_t warpType;
    uint32_t warpDestinationEntityId;
    int32_t dummypolyId;
};

struct WarpCharacterAndCopyFloor {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 42;
    uint32_t entityId;
    uint8_t warpType;
    uint32_t warpDestinationEntityId;
    int32_t dummypolyId;
    uint32_t entityIdToCopyFloorFrom;
};

struct RequestCharacterAnimationReset {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 43;
    uint32_t characterEntityId;
    uint8_t state;
};

struct BonfirelikeRecovery {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 47;
};

struct ChangeCharactersCloth {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 48;
    uint32_t entityId;
    uint8_t bitNumber;
    uint8_t stateId;
};

struct ChangeCharacterPatrolBehavior {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 49;
    uint32_t characterEntityId;
    uint32_t patrolInformationEntityId;
};

struct SetLockOnPoint {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 50;
    uint32_t entityId;
    int32_t lockOnDummypolyId;
    uint8_t desiredState;
};

struct ChangeCharacter {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 52;
    int32_t characterParamId;
};

struct SetCharacterTalkRange {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 55;
    uint32_t entityId;
    float range;
};

struct ConnectCharacterToCaravan {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 60;
    uint32_t characterEntityId;
    uint32_t caravanAssetEntityId;
};

struct Unknown200461 {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 61;
    int32_t unknown;
};

struct SetCharacterEnableDistance {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 63;
    uint32_t characterEntityId;
    float distance;
};

struct CopyPlayerCharacterData {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 67;
    uint32_t sourceCharacterEntityId;
    uint32_t targetCharacterEntityId;
};

struct AttachAssetToCharacter {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 68;
    uint32_t characterEntityId;
    int32_t dummypolyId;
    uint32_t assetEntityId;
};

struct SetCharacterDisableOnHitUnload {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 69;
    uint32_t characterEntityId;
    uint8_t state;
};

struct SetDistancebasedNetworkUpdateAuthority {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 70;
    uint32_t characterEntityId;
    uint8_t state;
};

struct Unknown200471 {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 71;
    int8_t unknown;
    uint32_t unknownEntityIdA;
    uint32_t unknownEntityIdB;
};

struct SetCharacterFadeOnEnable {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 73;
    uint32_t characterEntityId;
    uint8_t state;
};

struct WarpCharacterAndCopyFloorWithFadeout {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 74;
    uint32_t entityId;
    uint8_t warpType;
    uint32_t warpDestinationEntityId;
    int32_t dummypolyId;
    uint32_t entityIdToCopyFloorFrom;
    uint8_t useBonfireEffect;
    uint8_t resetCamera;
};

struct SetCharacterFaceParamOverride {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 75;
    uint32_t characterEntityId;
    int8_t overrideSlot;
    int32_t faceParamId;
};

struct Unknown200476 {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 76;
    uint32_t eventFlagId;
    int32_t itemLotId;
};

struct FadeToBlack {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 77;
    float fadeToBlackRatio;
    float fadeToBlackTimeS;
    uint8_t freezePlayer;
    float freezePlayerDelayS;
};

struct CopyCharacterDataFromOnlinePlayers {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 78;
    int8_t poolType;
    int32_t fallbackCharacterParamId;
    uint32_t targetEntityId;
};

struct RequestCharacterDataFromOnlinePlayers {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 79;
    int8_t poolType;
    int32_t unknown;
};

struct SendCharacterDataToOnlinePlayers {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 80;
    int8_t poolType;
};

struct ResetCharacterPosition {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 81;
    uint32_t characterEntityId;
};

struct SetSpecialStandbyEndedFlag {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 83;
    uint32_t characterEntityId;
    uint8_t flagState;
};

struct SetCharacterEnableDistanceAndUnknown200484 {
    static constexpr const int insBank = 2004;
    static constexpr const int insId = 84;
    uint32_t characterEntityId;
    float enableDistance;
    float unknownDistance;
};

struct RequestAssetDestruction {
    static constexpr const int insBank = 2005;
    static constexpr const int insId = 1;
    uint32_t entityId;
    int8_t slotNumber;
};

struct RequestAssetRestoration {
    static constexpr const int insBank = 2005;
    static constexpr const int insId = 2;
    uint32_t entityId;
};

struct ChangeAssetEnableState {
    static constexpr const int insBank = 2005;
    static constexpr const int insId = 3;
    uint32_t targetAssetEntityId;
    uint8_t state;
};

struct SetAssetTreasureState {
    static constexpr const int insBank = 2005;
    static constexpr const int insId = 4;
    uint32_t targetAssetEntityId;
    uint8_t state;
};

struct InitializeObjact {
    static constexpr const int insBank = 2005;
    static constexpr const int insId = 5;
    uint32_t entityId;
    int32_t objactParamId;
    int32_t relativeTargetIdx;
};

struct SetObjactState {
    static constexpr const int insBank = 2005;
    static constexpr const int insId = 6;
    uint32_t entityId;
    int32_t objactParamId;
    uint8_t state;
};

struct ReproduceAssetAnimation {
    static constexpr const int insBank = 2005;
    static constexpr const int insId = 7;
    uint32_t targetAssetEntityId;
    int32_t animationId;
};

struct ReproduceAssetDestruction {
    static constexpr const int insBank = 2005;
    static constexpr const int insId = 8;
    uint32_t entityId;
    int8_t slotNumber;
};

struct CreateDamagingAsset {
    static constexpr const int insBank = 2005;
    static constexpr const int insId = 9;
    uint32_t eventFlagId;
    uint32_t entityId;
    int32_t dummypolyId;
    int32_t behaviorId;
    int32_t target;
    float radius;
    float lifespan;
    float repetitionTimeS;
};

struct WarpAssetToCharacter {
    static constexpr const int insBank = 2005;
    static constexpr const int insId = 11;
    uint32_t entityId;
    uint32_t characterEntityId;
    int16_t dummypolyId;
};

struct DeleteAssetEvent {
    static constexpr const int insBank = 2005;
    static constexpr const int insId = 12;
    uint32_t eventFlagId;
};

struct SetAssetInvulnerability {
    static constexpr const int insBank = 2005;
    static constexpr const int insId = 13;
    uint32_t targetAssetEntityId;
    uint8_t state;
};

struct SetObjactStateAssignIdx {
    static constexpr const int insBank = 2005;
    static constexpr const int insId = 14;
    uint32_t entityId;
    int32_t objactParamId;
    int32_t relativeTargetIdx;
    uint8_t state;
};

struct RerollAssetTreasure {
    static constexpr const int insBank = 2005;
    static constexpr const int insId = 15;
    uint32_t targetAssetEntityId;
};

struct AttachCaravanToController {
    static constexpr const int insBank = 2005;
    static constexpr const int insId = 17;
    uint32_t caravanAssetEntityId;
    uint32_t characterEntityId;
};

struct AttachAssetToAsset {
    static constexpr const int insBank = 2005;
    static constexpr const int insId = 18;
    uint32_t childAssetEntityId;
    uint32_t parentAssetEntityId;
    int32_t parentDummypolyId;
};

struct CreateBigDamagingAsset {
    static constexpr const int insBank = 2005;
    static constexpr const int insId = 20;
    uint32_t eventFlagId;
    uint32_t entityId;
    int32_t startingDummypolyId;
    int32_t endingDummypolyId;
    int32_t behaviorId;
    int32_t target;
    float radius;
    float lifespan;
    float repetitionTimeS;
};

struct DeleteMapSFX {
    static constexpr const int insBank = 2006;
    static constexpr const int insId = 1;
    uint32_t entityId;
    uint8_t onlyDeleteRoot;
};

struct SpawnMapSFX {
    static constexpr const int insBank = 2006;
    static constexpr const int insId = 2;
    uint32_t entityId;
};

struct SpawnOneshotSFX {
    static constexpr const int insBank = 2006;
    static constexpr const int insId = 3;
    int32_t targetEntityType;
    uint32_t entityId;
    int32_t dummypolyId;
    int32_t sfxId;
};

struct CreateAssetfollowingSFX {
    static constexpr const int insBank = 2006;
    static constexpr const int insId = 4;
    uint32_t assetEntityId;
    int32_t dummypolyId;
    int32_t sfxId;
};

struct DeleteAssetfollowingSFX {
    static constexpr const int insBank = 2006;
    static constexpr const int insId = 5;
    uint32_t assetEntityId;
    int32_t shouldDeleteRoot;
};

struct SetWindSFX {
    static constexpr const int insBank = 2006;
    static constexpr const int insId = 6;
    int32_t windSFXId;
};

struct DisplayGenericDialog {
    static constexpr const int insBank = 2007;
    static constexpr const int insId = 1;
    int32_t messageId;
    int16_t dialogType;
    int16_t numberOfOptions;
    uint32_t entityId;
    float displayDistance;
};

struct DisplayBanner {
    static constexpr const int insBank = 2007;
    static constexpr const int insId = 2;
    uint8_t bannerType;
};

struct DisplayStatusMessage {
    static constexpr const int insBank = 2007;
    static constexpr const int insId = 3;
    int32_t messageId;
    uint8_t padState;
};

struct DisplayBlinkingMessage {
    static constexpr const int insBank = 2007;
    static constexpr const int insId = 4;
    int32_t messageId;
};

struct DisplayFullScreenMessage {
    static constexpr const int insBank = 2007;
    static constexpr const int insId = 9;
    int32_t messageId;
};

struct DisplayGenericDialogAndSetEventFlags {
    static constexpr const int insBank = 2007;
    static constexpr const int insId = 10;
    int32_t messageId;
    int16_t dialogType;
    int16_t numberOfOptions;
    uint32_t entityId;
    float displayDistance;
    uint32_t leftResponseEventFlagId;
    uint32_t rightResponseEventFlagId;
    uint32_t cancelResponseEventFlagId;
};

struct DisplayBlinkingMessageWithPriority {
    static constexpr const int insBank = 2007;
    static constexpr const int insId = 12;
    int32_t messageId;
    int16_t priority;
    uint8_t shouldInterrupt;
};

struct DisplaySubareaWelcomeMessage {
    static constexpr const int insBank = 2007;
    static constexpr const int insId = 13;
    int32_t messageId;
};

struct DisplayAreaWelcomeMessage {
    static constexpr const int insBank = 2007;
    static constexpr const int insId = 14;
    int32_t messageId;
};

struct ShowTutorialPopup {
    static constexpr const int insBank = 2007;
    static constexpr const int insId = 15;
    int32_t tutorialParamId;
    uint8_t unknown;
    uint8_t unknown2;
};

struct DisplayNetworkMessage {
    static constexpr const int insBank = 2007;
    static constexpr const int insId = 16;
    int32_t networkMessageId;
    uint8_t unknown;
};

struct ChangeCamera {
    static constexpr const int insBank = 2008;
    static constexpr const int insId = 1;
    int32_t normalCameraId;
    int32_t lockedCameraId;
};

struct SetCameraVibration {
    static constexpr const int insBank = 2008;
    static constexpr const int insId = 2;
    int32_t vibrationId;
    int32_t targetEntityType;
    uint32_t entityId;
    int32_t dummypolyId;
    float decayStartDistance;
    float decayEndDistance;
};

struct SetLockcamSlotNumber {
    static constexpr const int insBank = 2008;
    static constexpr const int insId = 3;
    uint8_t areaId;
    uint8_t blockId;
    uint16_t lockcamSlotNumber;
};

struct SetCameraAngle {
    static constexpr const int insBank = 2008;
    static constexpr const int insId = 4;
    float xAngle;
    float yAngle;
};

struct RegisterLadder {
    static constexpr const int insBank = 2009;
    static constexpr const int insId = 0;
    uint32_t disableTopEventFlagId;
    uint32_t disableBottomEventFlagId;
    uint32_t entityId;
};

struct RegisterBonfire {
    static constexpr const int insBank = 2009;
    static constexpr const int insId = 3;
    uint32_t eventFlagId;
    uint32_t entityId;
    float reactionDistance;
    float reactionAngle;
    int32_t setStandardKindlingLevel;
    float enemyDeactivationDistance;
};

struct ActivateMultiplayerdependantBuffs {
    static constexpr const int insBank = 2009;
    static constexpr const int insId = 4;
    uint32_t entityId;
};

struct IssueBossRoomEntryNotification {
    static constexpr const int insBank = 2009;
    static constexpr const int insId = 6;
    uint8_t dummy;
};

struct SendInvadingPhantomsHome {
    static constexpr const int insBank = 2009;
    static constexpr const int insId = 8;
    int32_t unknown;
};

struct SendAllPhantomsHome {
    static constexpr const int insBank = 2009;
    static constexpr const int insId = 11;
    int32_t dummy;
};

struct SendAllPhantomsHomeAndUpdateServerPvpStats {
    static constexpr const int insBank = 2009;
    static constexpr const int insId = 12;
    int32_t unknown;
};

struct PlaySE {
    static constexpr const int insBank = 2010;
    static constexpr const int insId = 2;
    uint32_t entityId;
    int32_t soundType;
    int32_t soundId;
};

struct SuppressSE {
    static constexpr const int insBank = 2010;
    static constexpr const int insId = 7;
    int32_t soundType;
    int32_t unknown;
    uint8_t isSuppressionActive;
};

struct Unknown201008 {
    static constexpr const int insBank = 2010;
    static constexpr const int insId = 8;
    int32_t unknown;
};

struct SetBossBgm {
    static constexpr const int insBank = 2010;
    static constexpr const int insId = 10;
    int32_t bgmBossConvParamId;
    int32_t state;
};

struct SuppressSoundForFogGate {
    static constexpr const int insBank = 2010;
    static constexpr const int insId = 11;
    float timeS;
};

struct SetFieldBattleBgmHeatUp {
    static constexpr const int insBank = 2010;
    static constexpr const int insId = 12;
    uint32_t npcThreatLevel;
    uint8_t heatUp;
};

struct ActivateHit {
    static constexpr const int insBank = 2011;
    static constexpr const int insId = 1;
    uint32_t hitEntityId;
    uint8_t state;
};

struct ActivateHitBackreadMask {
    static constexpr const int insBank = 2011;
    static constexpr const int insId = 2;
    uint32_t hitEntityId;
    uint8_t state;
};

struct ActivateHitres {
    static constexpr const int insBank = 2011;
    static constexpr const int insId = 3;
    uint32_t hitEntityId;
    uint8_t state;
};

struct ActivateMapPart {
    static constexpr const int insBank = 2012;
    static constexpr const int insId = 1;
    uint32_t mapPartEntityId;
    uint8_t state;
};

struct SetAreaWelcomeMessageState {
    static constexpr const int insBank = 2012;
    static constexpr const int insId = 8;
    uint8_t state;
};

struct ActivateGparamOverride {
    static constexpr const int insBank = 2012;
    static constexpr const int insId = 11;
    int32_t gparamSubId;
    float changeTimeS;
};

struct DeactivateGparamOverride {
    static constexpr const int insBank = 2012;
    static constexpr const int insId = 12;
    float changeTimeS;
};

}
