/*
 * NetPacksLib.cpp, part of VCMI engine
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 *
 */
#include "StdInc.h"
#include "ArtifactUtils.h"
#include "PacksForClient.h"
#include "PacksForClientBattle.h"
#include "PacksForServer.h"
#include "StackLocation.h"
#include "PacksForLobby.h"
#include "SetStackEffect.h"
#include "NetPackVisitor.h"
#include "CGeneralTextHandler.h"
#include "CArtHandler.h"
#include "CHeroHandler.h"
#include "VCMI_Lib.h"
#include "mapping/CMap.h"
#include "spells/CSpellHandler.h"
#include "CCreatureHandler.h"
#include "gameState/CGameState.h"
#include "gameState/TavernHeroesPool.h"
#include "CStack.h"
#include "battle/BattleInfo.h"
#include "CTownHandler.h"
#include "mapping/CMapInfo.h"
#include "StartInfo.h"
#include "CPlayerState.h"
#include "TerrainHandler.h"
#include "mapObjects/CGCreature.h"
#include "mapObjects/CGMarket.h"
#include "mapObjects/CGTownInstance.h"
#include "mapObjects/CQuest.h"
#include "mapObjects/MiscObjects.h"
#include "mapObjectConstructors/AObjectTypeHandler.h"
#include "mapObjectConstructors/CObjectClassesHandler.h"
#include "campaign/CampaignState.h"
#include "GameSettings.h"

VCMI_LIB_NAMESPACE_BEGIN

void CPack::visit(ICPackVisitor & visitor)
{
	visitBasic(visitor);

	// visitBasic may destroy this and in such cases we do not want to call visitTyped
	if(visitor.callTyped())
	{
		visitTyped(visitor);
	}
}

void CPack::visitBasic(ICPackVisitor & visitor)
{
}

void CPack::visitTyped(ICPackVisitor & visitor)
{
}

void CPackForClient::visitBasic(ICPackVisitor & visitor)
{
	visitor.visitForClient(*this);
}

void CPackForServer::visitBasic(ICPackVisitor & visitor)
{
	visitor.visitForServer(*this);
}

void CPackForLobby::visitBasic(ICPackVisitor & visitor)
{
	visitor.visitForLobby(*this);
}

bool CPackForLobby::isForServer() const
{
	return false;
}

bool CLobbyPackToServer::isForServer() const
{
	return true;
}

void PackageApplied::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitPackageApplied(*this);
}

void SystemMessage::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitSystemMessage(*this);
}

void PlayerBlocked::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitPlayerBlocked(*this);
}

void PlayerCheated::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitPlayerCheated(*this);
}

void PlayerStartsTurn::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitPlayerStartsTurn(*this);
}

void DaysWithoutTown::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitDaysWithoutTown(*this);
}

void EntitiesChanged::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitEntitiesChanged(*this);
}

void SetResources::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitSetResources(*this);
}

void SetPrimSkill::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitSetPrimSkill(*this);
}

void SetSecSkill::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitSetSecSkill(*this);
}

void HeroVisitCastle::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitHeroVisitCastle(*this);
}

void ChangeSpells::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitChangeSpells(*this);
}

void SetMana::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitSetMana(*this);
}

void SetMovePoints::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitSetMovePoints(*this);
}

void FoWChange::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitFoWChange(*this);
}

void SetAvailableHero::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitSetAvailableHeroes(*this);
}

void GiveBonus::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitGiveBonus(*this);
}

void ChangeObjPos::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitChangeObjPos(*this);
}

void PlayerEndsTurn::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitPlayerEndsTurn(*this);
}

void PlayerEndsGame::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitPlayerEndsGame(*this);
}

void PlayerReinitInterface::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitPlayerReinitInterface(*this);
}

void RemoveBonus::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitRemoveBonus(*this);
}

void SetCommanderProperty::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitSetCommanderProperty(*this);
}

void AddQuest::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitAddQuest(*this);
}

void UpdateArtHandlerLists::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitUpdateArtHandlerLists(*this);
}

void UpdateMapEvents::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitUpdateMapEvents(*this);
}

void UpdateCastleEvents::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitUpdateCastleEvents(*this);
}

void ChangeFormation::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitChangeFormation(*this);
}

void RemoveObject::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitRemoveObject(*this);
}

void TryMoveHero::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitTryMoveHero(*this);
}

void NewStructures::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitNewStructures(*this);
}

void RazeStructures::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitRazeStructures(*this);
}

void SetAvailableCreatures::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitSetAvailableCreatures(*this);
}

void SetHeroesInTown::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitSetHeroesInTown(*this);
}

void HeroRecruited::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitHeroRecruited(*this);
}

void GiveHero::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitGiveHero(*this);
}

void OpenWindow::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitOpenWindow(*this);
}

void NewObject::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitNewObject(*this);
}

void SetAvailableArtifacts::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitSetAvailableArtifacts(*this);
}

void NewArtifact::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitNewArtifact(*this);
}

void ChangeStackCount::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitChangeStackCount(*this);
}

void SetStackType::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitSetStackType(*this);
}

void EraseStack::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitEraseStack(*this);
}

void SwapStacks::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitSwapStacks(*this);
}

void InsertNewStack::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitInsertNewStack(*this);
}

void RebalanceStacks::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitRebalanceStacks(*this);
}

void BulkRebalanceStacks::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitBulkRebalanceStacks(*this);
}

void BulkSmartRebalanceStacks::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitBulkSmartRebalanceStacks(*this);
}

void PutArtifact::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitPutArtifact(*this);
}

void EraseArtifact::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitEraseArtifact(*this);
}

void BulkMoveArtifacts::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitBulkMoveArtifacts(*this);
}

void AssembledArtifact::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitAssembledArtifact(*this);
}

void DisassembledArtifact::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitDisassembledArtifact(*this);
}

void HeroVisit::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitHeroVisit(*this);
}

void NewTurn::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitNewTurn(*this);
}

void InfoWindow::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitInfoWindow(*this);
}

void SetObjectProperty::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitSetObjectProperty(*this);
}

void ChangeObjectVisitors::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitChangeObjectVisitors(*this);
}

void ChangeArtifactsCostume::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitChangeArtifactsCostume(*this);
}

void HeroLevelUp::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitHeroLevelUp(*this);
}

void CommanderLevelUp::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitCommanderLevelUp(*this);
}

void BlockingDialog::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitBlockingDialog(*this);
}

void GarrisonDialog::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitGarrisonDialog(*this);
}

void ExchangeDialog::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitExchangeDialog(*this);
}

void TeleportDialog::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitTeleportDialog(*this);
}

void MapObjectSelectDialog::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitMapObjectSelectDialog(*this);
}

void BattleStart::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitBattleStart(*this);
}

void BattleNextRound::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitBattleNextRound(*this);
}

void BattleSetActiveStack::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitBattleSetActiveStack(*this);
}

void BattleResult::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitBattleResult(*this);
}

void BattleLogMessage::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitBattleLogMessage(*this);
}

void BattleStackMoved::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitBattleStackMoved(*this);
}

void BattleUnitsChanged::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitBattleUnitsChanged(*this);
}

void BattleAttack::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitBattleAttack(*this);
}

void StartAction::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitStartAction(*this);
}

void EndAction::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitEndAction(*this);
}

void BattleSpellCast::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitBattleSpellCast(*this);
}

void SetStackEffect::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitSetStackEffect(*this);
}

void StacksInjured::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitStacksInjured(*this);
}

void BattleResultsApplied::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitBattleResultsApplied(*this);
}

void BattleObstaclesChanged::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitBattleObstaclesChanged(*this);
}

void BattleSetStackProperty::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitBattleSetStackProperty(*this);
}

void BattleTriggerEffect::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitBattleTriggerEffect(*this);
}

void BattleUpdateGateState::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitBattleUpdateGateState(*this);
}

void AdvmapSpellCast::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitAdvmapSpellCast(*this);
}

void ShowWorldViewEx::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitShowWorldViewEx(*this);
}

void EndTurn::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitEndTurn(*this);
}

void GamePause::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitGamePause(*this);
}

void DismissHero::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitDismissHero(*this);
}

void MoveHero::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitMoveHero(*this);
}

void CastleTeleportHero::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitCastleTeleportHero(*this);
}

void ArrangeStacks::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitArrangeStacks(*this);
}

void BulkMoveArmy::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitBulkMoveArmy(*this);
}

void BulkSplitStack::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitBulkSplitStack(*this);
}

void BulkMergeStacks::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitBulkMergeStacks(*this);
}

void BulkSmartSplitStack::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitBulkSmartSplitStack(*this);
}

void DisbandCreature::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitDisbandCreature(*this);
}

void BuildStructure::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitBuildStructure(*this);
}

void RazeStructure::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitRazeStructure(*this);
}

void RecruitCreatures::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitRecruitCreatures(*this);
}

void UpgradeCreature::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitUpgradeCreature(*this);
}

void GarrisonHeroSwap::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitGarrisonHeroSwap(*this);
}

void ExchangeArtifacts::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitExchangeArtifacts(*this);
}

void BulkExchangeArtifacts::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitBulkExchangeArtifacts(*this);
}

void ManageBackpackArtifacts::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitManageBackpackArtifacts(*this);
}

void ManageEquippedArtifacts::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitManageEquippedArtifacts(*this);
}

void AssembleArtifacts::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitAssembleArtifacts(*this);
}

void EraseArtifactByClient::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitEraseArtifactByClient(*this);
}

void BuyArtifact::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitBuyArtifact(*this);
}

void TradeOnMarketplace::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitTradeOnMarketplace(*this);
}

void SetFormation::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitSetFormation(*this);
}

void HireHero::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitHireHero(*this);
}

void BuildBoat::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitBuildBoat(*this);
}

void QueryReply::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitQueryReply(*this);
}

void MakeAction::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitMakeAction(*this);
}

void DigWithHero::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitDigWithHero(*this);
}

void CastAdvSpell::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitCastAdvSpell(*this);
}

void SaveGame::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitSaveGame(*this);
}

void PlayerMessage::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitPlayerMessage(*this);
}

void PlayerMessageClient::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitPlayerMessageClient(*this);
}

void CenterView::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitCenterView(*this);
}

void LobbyClientConnected::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitLobbyClientConnected(*this);
}

void LobbyClientDisconnected::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitLobbyClientDisconnected(*this);
}

void LobbyChatMessage::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitLobbyChatMessage(*this);
}

void LobbyGuiAction::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitLobbyGuiAction(*this);
}

void LobbyLoadProgress::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitLobbyLoadProgress(*this);
}

void LobbyRestartGame::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitLobbyRestartGame(*this);
}

void LobbyStartGame::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitLobbyStartGame(*this);
}

void LobbyPrepareStartGame::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitLobbyPrepareStartGame(*this);
}

void LobbyChangeHost::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitLobbyChangeHost(*this);
}

void LobbyUpdateState::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitLobbyUpdateState(*this);
}

void LobbySetMap::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitLobbySetMap(*this);
}

void LobbySetCampaign::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitLobbySetCampaign(*this);
}

void LobbySetCampaignMap::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitLobbySetCampaignMap(*this);
}

void LobbySetCampaignBonus::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitLobbySetCampaignBonus(*this);
}

void LobbyChangePlayerOption::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitLobbyChangePlayerOption(*this);
}

void LobbySetPlayer::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitLobbySetPlayer(*this);
}

void LobbySetPlayerName::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitLobbySetPlayerName(*this);
}

void LobbySetSimturns::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitLobbySetSimturns(*this);
}

void LobbySetTurnTime::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitLobbySetTurnTime(*this);
}

void LobbySetExtraOptions::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitLobbySetExtraOptions(*this);
}

void LobbySetDifficulty::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitLobbySetDifficulty(*this);
}

void LobbyForceSetPlayer::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitLobbyForceSetPlayer(*this);
}

void LobbyShowMessage::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitLobbyShowMessage(*this);
}

void LobbyPvPAction::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitLobbyPvPAction(*this);
}

void SetResources::applyGs(CGameState * gs) const
{
	assert(player.isValidPlayer());
	if(abs)
		gs->getPlayerState(player)->resources = res;
	else
		gs->getPlayerState(player)->resources += res;
	gs->getPlayerState(player)->resources.amin(GameConstants::PLAYER_RESOURCES_CAP);

	//just ensure that player resources are not negative
	//server is responsible to check if player can afford deal
	//but events on server side are allowed to take more than player have
	gs->getPlayerState(player)->resources.positive();
}

void SetPrimSkill::applyGs(CGameState * gs) const
{
	CGHeroInstance * hero = gs->getHero(id);
	assert(hero);
	hero->setPrimarySkill(which, val, abs);
}

void SetSecSkill::applyGs(CGameState * gs) const
{
	CGHeroInstance *hero = gs->getHero(id);
	hero->setSecSkillLevel(which, val, abs);
}

void SetCommanderProperty::applyGs(CGameState *gs)
{
	CCommanderInstance * commander = gs->getHero(heroid)->commander;
	assert (commander);

	switch (which)
	{
		case BONUS:
			commander->accumulateBonus (std::make_shared<Bonus>(accumulatedBonus));
			break;
		case SPECIAL_SKILL:
			commander->accumulateBonus (std::make_shared<Bonus>(accumulatedBonus));
			commander->specialSkills.insert (additionalInfo);
			break;
		case SECONDARY_SKILL:
			commander->secondarySkills[additionalInfo] = static_cast<ui8>(amount);
			break;
		case ALIVE:
			if (amount)
				commander->setAlive(true);
			else
				commander->setAlive(false);
			break;
		case EXPERIENCE:
			commander->giveStackExp(amount); //TODO: allow setting exp for stacks via netpacks
			break;
	}
}

void AddQuest::applyGs(CGameState * gs) const
{
	assert (vstd::contains(gs->players, player));
	auto * vec = &gs->players[player].quests;
	if (!vstd::contains(*vec, quest))
		vec->push_back (quest);
	else
		logNetwork->warn("Warning! Attempt to add duplicated quest");
}

void UpdateArtHandlerLists::applyGs(CGameState * gs) const
{
	gs->allocatedArtifacts = allocatedArtifacts;
}

void UpdateMapEvents::applyGs(CGameState * gs) const
{
	gs->map->events = events;
}

void UpdateCastleEvents::applyGs(CGameState * gs) const
{
	auto * t = gs->getTown(town);
	t->events = events;
}

void ChangeFormation::applyGs(CGameState * gs) const
{
	gs->getHero(hid)->setFormation(formation);
}

void HeroVisitCastle::applyGs(CGameState * gs) const
{
	CGHeroInstance *h = gs->getHero(hid);
	CGTownInstance *t = gs->getTown(tid);

	assert(h);
	assert(t);

	if(start())
		t->setVisitingHero(h);
	else
		t->setVisitingHero(nullptr);
}

void ChangeSpells::applyGs(CGameState *gs)
{
	CGHeroInstance *hero = gs->getHero(hid);

	if(learn)
		for(const auto & sid : spells)
			hero->addSpellToSpellbook(sid);
	else
		for(const auto & sid : spells)
			hero->removeSpellFromSpellbook(sid);
}

void SetMana::applyGs(CGameState * gs) const
{
	CGHeroInstance * hero = gs->getHero(hid);

	assert(hero);

	if(absolute)
		hero->mana = val;
	else
		hero->mana += val;

	vstd::amax(hero->mana, 0); //not less than 0
}

void SetMovePoints::applyGs(CGameState * gs) const
{
	CGHeroInstance *hero = gs->getHero(hid);

	assert(hero);

	if(absolute)
		hero->setMovementPoints(val);
	else
		hero->setMovementPoints(hero->movementPointsRemaining() + val);
}

void FoWChange::applyGs(CGameState *gs)
{
	TeamState * team = gs->getPlayerTeam(player);
	auto & fogOfWarMap = team->fogOfWarMap;
	for(const int3 & t : tiles)
		fogOfWarMap[t.z][t.x][t.y] = mode != ETileVisibility::HIDDEN;

	if (mode == ETileVisibility::HIDDEN) //do not hide too much
	{
		std::unordered_set<int3> tilesRevealed;
		for (auto & elem : gs->map->objects)
		{
			const CGObjectInstance *o = elem;
			if (o)
			{
				switch(o->ID.toEnum())
				{
				case Obj::HERO:
				case Obj::MINE:
				case Obj::TOWN:
				case Obj::ABANDONED_MINE:
					if(vstd::contains(team->players, o->tempOwner)) //check owned observators
						gs->getTilesInRange(tilesRevealed, o->getSightCenter(), o->getSightRadius(), ETileVisibility::HIDDEN, o->tempOwner);
					break;
				}
			}
		}
		for(const int3 & t : tilesRevealed) //probably not the most optimal solution ever
			fogOfWarMap[t.z][t.x][t.y] = 1;
	}
}

void SetAvailableHero::applyGs(CGameState *gs)
{
	gs->heroesPool->setHeroForPlayer(player, slotID, hid, army, roleID, replenishPoints);
}

void GiveBonus::applyGs(CGameState *gs)
{
	CBonusSystemNode *cbsn = nullptr;
	switch(who)
	{
	case ETarget::OBJECT:
		cbsn = dynamic_cast<CBonusSystemNode*>(gs->getObjInstance(id.as<ObjectInstanceID>()));
		break;
	case ETarget::PLAYER:
		cbsn = gs->getPlayerState(id.as<PlayerColor>());
		break;
	case ETarget::BATTLE:
		assert(Bonus::OneBattle(&bonus));
		cbsn = dynamic_cast<CBonusSystemNode*>(gs->getBattle(id.as<BattleID>()));
		break;
	}

	assert(cbsn);

	if(Bonus::OneWeek(&bonus))
		bonus.turnsRemain = 8 - gs->getDate(Date::DAY_OF_WEEK); // set correct number of days before adding bonus

	auto b = std::make_shared<Bonus>(bonus);
	cbsn->addNewBonus(b);
}

void ChangeObjPos::applyGs(CGameState *gs)
{
	CGObjectInstance *obj = gs->getObjInstance(objid);
	if(!obj)
	{
		logNetwork->error("Wrong ChangeObjPos: object %d doesn't exist!", objid.getNum());
		return;
	}
	gs->map->removeBlockVisTiles(obj);
	obj->pos = nPos + obj->getVisitableOffset();
	gs->map->addBlockVisTiles(obj);
}

void ChangeObjectVisitors::applyGs(CGameState * gs) const
{
	switch (mode) {
		case VISITOR_ADD:
			gs->getHero(hero)->visitedObjects.insert(object);
			gs->getPlayerState(gs->getHero(hero)->tempOwner)->visitedObjects.insert(object);
			break;
		case VISITOR_ADD_TEAM:
			{
				TeamState *ts = gs->getPlayerTeam(gs->getHero(hero)->tempOwner);
				for(const auto & color : ts->players)
				{
					gs->getPlayerState(color)->visitedObjects.insert(object);
				}
			}
			break;
		case VISITOR_CLEAR:
			for (CGHeroInstance * hero : gs->map->allHeroes)
			{
				if (hero)
				{
					hero->visitedObjects.erase(object); // remove visit info from all heroes, including those that are not present on map
				}
			}

			for(auto &elem : gs->players)
			{
				elem.second.visitedObjects.erase(object);
			}

			break;
		case VISITOR_GLOBAL:
			{
				CGObjectInstance * objectPtr = gs->getObjInstance(object);
				gs->getPlayerState(gs->getHero(hero)->tempOwner)->visitedObjectsGlobal.insert({objectPtr->ID, objectPtr->subID});
				break;
			}
		case VISITOR_REMOVE:
			gs->getHero(hero)->visitedObjects.erase(object);
			break;
	}
}

void ChangeArtifactsCostume::applyGs(CGameState * gs) const
{
	auto & allCostumes = gs->getPlayerState(player)->costumesArtifacts;
	if(const auto & costume = allCostumes.find(costumeIdx); costume != allCostumes.end())
		costume->second = costumeSet;
	else
		allCostumes.try_emplace(costumeIdx, costumeSet);
}

void PlayerEndsGame::applyGs(CGameState * gs) const
{
	PlayerState *p = gs->getPlayerState(player);
	if(victoryLossCheckResult.victory())
	{
		p->status = EPlayerStatus::WINNER;

		// TODO: Campaign-specific code might as well go somewhere else
		// keep all heroes from the winning player
		if(p->human && gs->scenarioOps->campState)
		{
			std::vector<CGHeroInstance *> crossoverHeroes;
			for (CGHeroInstance * hero : gs->map->heroesOnMap)
				if (hero->tempOwner == player)
					crossoverHeroes.push_back(hero);

			gs->scenarioOps->campState->setCurrentMapAsConquered(crossoverHeroes);
		}
	}
	else
	{
		p->status = EPlayerStatus::LOSER;
	}

	// defeated player may be making turn right now
	gs->actingPlayers.erase(player);
}

void PlayerReinitInterface::applyGs(CGameState *gs)
{
	if(!gs || !gs->scenarioOps)
		return;
	
	//TODO: what does mean if more that one player connected?
	if(playerConnectionId == PlayerSettings::PLAYER_AI)
	{
		for(const auto & player : players)
			gs->scenarioOps->getIthPlayersSettings(player).connectedPlayerIDs.clear();
	}
}

void RemoveBonus::applyGs(CGameState *gs)
{
	CBonusSystemNode *node = nullptr;
	switch(who)
	{
	case GiveBonus::ETarget::OBJECT:
		node = dynamic_cast<CBonusSystemNode*>(gs->getObjInstance(whoID.as<ObjectInstanceID>()));
		break;
	case GiveBonus::ETarget::PLAYER:
		node = gs->getPlayerState(whoID.as<PlayerColor>());
		break;
	case GiveBonus::ETarget::BATTLE:
		assert(Bonus::OneBattle(&bonus));
		node = dynamic_cast<CBonusSystemNode*>(gs->getBattle(whoID.as<BattleID>()));
		break;
	}

	BonusList &bonuses = node->getExportedBonusList();

	for(const auto & b : bonuses)
	{
		if(b->source == source && b->sid == id)
		{
			bonus = *b; //backup bonus (to show to interfaces later)
			node->removeBonus(b);
			break;
		}
	}
}

void RemoveObject::applyGs(CGameState *gs)
{

	CGObjectInstance *obj = gs->getObjInstance(objectID);
	logGlobal->debug("removing object id=%d; address=%x; name=%s", objectID, (intptr_t)obj, obj->getObjectName());
	//unblock tiles
	gs->map->removeBlockVisTiles(obj);

	if (initiator.isValidPlayer())
		gs->getPlayerState(initiator)->destroyedObjects.insert(objectID);

	if(obj->ID == Obj::HERO) //remove beaten hero
	{
		auto * beatenHero = dynamic_cast<CGHeroInstance *>(obj);
		assert(beatenHero);
		PlayerState * p = gs->getPlayerState(beatenHero->tempOwner);
		gs->map->heroesOnMap -= beatenHero;
		p->heroes -= beatenHero;


		auto * siegeNode = beatenHero->whereShouldBeAttachedOnSiege(gs);

		// FIXME: workaround:
		// hero should be attached to siegeNode after battle
		// however this code might also be called on dismissing hero while in town
		if (siegeNode && vstd::contains(beatenHero->getParentNodes(), siegeNode))
				beatenHero->detachFrom(*siegeNode);

		beatenHero->tempOwner = PlayerColor::NEUTRAL; //no one owns beaten hero
		vstd::erase_if(beatenHero->artifactsInBackpack, [](const ArtSlotInfo& asi)
		{
			return asi.artifact->artType->getId() == ArtifactID::GRAIL;
		});

		if(beatenHero->visitedTown)
		{
			if(beatenHero->visitedTown->garrisonHero == beatenHero)
				beatenHero->visitedTown->garrisonHero = nullptr;
			else
				beatenHero->visitedTown->visitingHero = nullptr;

			beatenHero->visitedTown = nullptr;
			beatenHero->inTownGarrison = false;
		}
		//return hero to the pool, so he may reappear in tavern

		gs->heroesPool->addHeroToPool(beatenHero);
		gs->map->objects[objectID.getNum()] = nullptr;

		//If hero on Boat is removed, the Boat disappears
		if(beatenHero->boat)
		{
			beatenHero->detachFrom(const_cast<CGBoat&>(*beatenHero->boat));
			gs->map->instanceNames.erase(beatenHero->boat->instanceName);
			gs->map->objects[beatenHero->boat->id.getNum()].dellNull();
			beatenHero->boat = nullptr;
		}
		return;
	}

	const auto * quest = dynamic_cast<const IQuestObject *>(obj);
	if (quest)
	{
		gs->map->quests[quest->quest->qid] = nullptr;
		for (auto &player : gs->players)
		{
			vstd::erase_if(player.second.quests, [obj](const QuestInfo & q){
				return q.obj == obj;
			});
		}
	}

	gs->map->instanceNames.erase(obj->instanceName);
	gs->map->objects[objectID.getNum()].dellNull();
	gs->map->calculateGuardingGreaturePositions();//FIXME: excessive, update only affected tiles
}

static int getDir(const int3 & src, const int3 & dst)
{
	int ret = -1;
	if(dst.x+1 == src.x && dst.y+1 == src.y) //tl
	{
		ret = 1;
	}
	else if(dst.x == src.x && dst.y+1 == src.y) //t
	{
		ret = 2;
	}
	else if(dst.x-1 == src.x && dst.y+1 == src.y) //tr
	{
		ret = 3;
	}
	else if(dst.x-1 == src.x && dst.y == src.y) //r
	{
		ret = 4;
	}
	else if(dst.x-1 == src.x && dst.y-1 == src.y) //br
	{
		ret = 5;
	}
	else if(dst.x == src.x && dst.y-1 == src.y) //b
	{
		ret = 6;
	}
	else if(dst.x+1 == src.x && dst.y-1 == src.y) //bl
	{
		ret = 7;
	}
	else if(dst.x+1 == src.x && dst.y == src.y) //l
	{
		ret = 8;
	}
	return ret;
}

void TryMoveHero::applyGs(CGameState *gs)
{
	CGHeroInstance *h = gs->getHero(id);
	if (!h)
	{
		logGlobal->error("Attempt ot move unavailable hero %d", id.getNum());
		return;
	}

	h->setMovementPoints(movePoints);

	if((result == SUCCESS || result == BLOCKING_VISIT || result == EMBARK || result == DISEMBARK) && start != end)
	{
		auto dir = getDir(start,end);
		if(dir > 0  &&  dir <= 8)
			h->moveDir = dir;
		//else don`t change move direction - hero might have traversed the subterranean gate, direction should be kept
	}

	if(result == EMBARK) //hero enters boat at destination tile
	{
		const TerrainTile &tt = gs->map->getTile(h->convertToVisitablePos(end));
		assert(tt.visitableObjects.size() >= 1  &&  tt.visitableObjects.back()->ID == Obj::BOAT); //the only visitable object at destination is Boat
		auto * boat = dynamic_cast<CGBoat *>(tt.visitableObjects.back());
		assert(boat);

		gs->map->removeBlockVisTiles(boat); //hero blockvis mask will be used, we don't need to duplicate it with boat
		h->boat = boat;
		h->attachTo(*boat);
		boat->hero = h;
	}
	else if(result == DISEMBARK) //hero leaves boat to destination tile
	{
		auto * b = const_cast<CGBoat *>(h->boat);
		b->direction = h->moveDir;
		b->pos = start;
		b->hero = nullptr;
		gs->map->addBlockVisTiles(b);
		h->detachFrom(*b);
		h->boat = nullptr;
	}

	if(start!=end && (result == SUCCESS || result == TELEPORTATION || result == EMBARK || result == DISEMBARK))
	{
		gs->map->removeBlockVisTiles(h);
		h->pos = end;
		if(auto * b = const_cast<CGBoat *>(h->boat))
			b->pos = end;
		gs->map->addBlockVisTiles(h);
	}

	auto & fogOfWarMap = gs->getPlayerTeam(h->getOwner())->fogOfWarMap;
	for(const int3 & t : fowRevealed)
		fogOfWarMap[t.z][t.x][t.y] = 1;
}

void NewStructures::applyGs(CGameState *gs)
{
	CGTownInstance *t = gs->getTown(tid);

	for(const auto & id : bid)
	{
		assert(t->town->buildings.at(id) != nullptr);
		t->builtBuildings.insert(id);
		t->updateAppearance();
		auto currentBuilding = t->town->buildings.at(id);

		if(currentBuilding->overrideBids.empty())
			continue;

		for(const auto & overrideBid : currentBuilding->overrideBids)
		{
			t->overriddenBuildings.insert(overrideBid);
			t->deleteTownBonus(overrideBid);
		}
	}
	t->built = built;
	t->recreateBuildingsBonuses();
}

void RazeStructures::applyGs(CGameState *gs)
{
	CGTownInstance *t = gs->getTown(tid);
	for(const auto & id : bid)
	{
		t->builtBuildings.erase(id);

		t->updateAppearance();
	}
	t->destroyed = destroyed; //yeaha
	t->recreateBuildingsBonuses();
}

void SetAvailableCreatures::applyGs(CGameState * gs) const
{
	auto * dw = dynamic_cast<CGDwelling *>(gs->getObjInstance(tid));
	assert(dw);
	dw->creatures = creatures;
}

void SetHeroesInTown::applyGs(CGameState * gs) const
{
	CGTownInstance *t = gs->getTown(tid);

	CGHeroInstance * v = gs->getHero(visiting);
	CGHeroInstance * g = gs->getHero(garrison);

	bool newVisitorComesFromGarrison = v && v == t->garrisonHero;
	bool newGarrisonComesFromVisiting = g && g == t->visitingHero;

	if(newVisitorComesFromGarrison)
		t->setGarrisonedHero(nullptr);
	if(newGarrisonComesFromVisiting)
		t->setVisitingHero(nullptr);
	if(!newGarrisonComesFromVisiting || v)
		t->setVisitingHero(v);
	if(!newVisitorComesFromGarrison || g)
		t->setGarrisonedHero(g);

	if(v)
	{
		gs->map->addBlockVisTiles(v);
	}
	if(g)
	{
		gs->map->removeBlockVisTiles(g);
	}
}

void HeroRecruited::applyGs(CGameState * gs) const
{
	CGHeroInstance *h = gs->heroesPool->takeHeroFromPool(hid);
	CGTownInstance *t = gs->getTown(tid);
	PlayerState *p = gs->getPlayerState(player);

	if (boatId != ObjectInstanceID::NONE)
	{
		CGObjectInstance *obj = gs->getObjInstance(boatId);
		auto * boat = dynamic_cast<CGBoat *>(obj);
		if (boat)
		{
			gs->map->removeBlockVisTiles(boat);
			h->attachToBoat(boat);
		}
	}

	h->setOwner(player);
	h->pos = tile;
	h->initObj(gs->getRandomGenerator());

	if(h->id == ObjectInstanceID())
	{
		h->id = ObjectInstanceID(static_cast<si32>(gs->map->objects.size()));
		gs->map->objects.emplace_back(h);
	}
	else
		gs->map->objects[h->id.getNum()] = h;

	gs->map->heroesOnMap.emplace_back(h);
	p->heroes.emplace_back(h);
	h->attachTo(*p);
	gs->map->addBlockVisTiles(h);

	if(t)
		t->setVisitingHero(h);
}

void GiveHero::applyGs(CGameState * gs) const
{
	CGHeroInstance *h = gs->getHero(id);

	if (boatId != ObjectInstanceID::NONE)
	{
		CGObjectInstance *obj = gs->getObjInstance(boatId);
		auto * boat = dynamic_cast<CGBoat *>(obj);
		if (boat)
		{
			gs->map->removeBlockVisTiles(boat);
			h->attachToBoat(boat);
		}
	}

	//bonus system
	h->detachFrom(gs->globalEffects);
	h->attachTo(*gs->getPlayerState(player));

	auto oldVisitablePos = h->visitablePos();
	gs->map->removeBlockVisTiles(h,true);
	h->appearance = VLC->objtypeh->getHandlerFor(Obj::HERO, h->type->heroClass->getIndex())->getTemplates().front();

	h->setOwner(player);
	h->setMovementPoints(h->movementPointsLimit(true));
	h->pos = h->convertFromVisitablePos(oldVisitablePos);
	gs->map->heroesOnMap.emplace_back(h);
	gs->getPlayerState(h->getOwner())->heroes.emplace_back(h);

	gs->map->addBlockVisTiles(h);
	h->inTownGarrison = false;
}

void NewObject::applyGs(CGameState *gs)
{
	TerrainId terrainType = ETerrainId::NONE;

	if (!gs->isInTheMap(targetPos))
	{
		logGlobal->error("Attempt to create object outside map at %s!", targetPos.toString());
		return;
	}

	const TerrainTile & t = gs->map->getTile(targetPos);
	terrainType = t.terType->getId();

	auto handler = VLC->objtypeh->getHandlerFor(ID, subID);

	CGObjectInstance * o = handler->create(gs->callback, nullptr);
	handler->configureObject(o, gs->getRandomGenerator());
	assert(o->ID == this->ID);
	
	if (ID == Obj::MONSTER) //probably more options will be needed
	{
		//CStackInstance hlp;
		auto * cre = dynamic_cast<CGCreature *>(o);
		//cre->slots[0] = hlp;
		assert(cre);
		cre->notGrowingTeam = cre->neverFlees = false;
		cre->character = 2;
		cre->gainedArtifact = ArtifactID::NONE;
		cre->identifier = -1;
		cre->addToSlot(SlotID(0), new CStackInstance(subID.getNum(), -1)); //add placeholder stack
	}

	assert(!handler->getTemplates(terrainType).empty());
	if (handler->getTemplates().empty())
	{
		logGlobal->error("Attempt to create object (%d %d) with no templates!", ID, subID.getNum());
		return;
	}

	if (!handler->getTemplates(terrainType).empty())
		o->appearance = handler->getTemplates(terrainType).front();
	else
		o->appearance = handler->getTemplates().front();

	o->id = ObjectInstanceID(static_cast<si32>(gs->map->objects.size()));
	o->pos = targetPos + o->getVisitableOffset();

	gs->map->objects.emplace_back(o);
	gs->map->addBlockVisTiles(o);
	o->initObj(gs->getRandomGenerator());
	gs->map->calculateGuardingGreaturePositions();

	createdObjectID = o->id;

	logGlobal->debug("Added object id=%d; address=%x; name=%s", o->id, (intptr_t)o, o->getObjectName());
}

void NewArtifact::applyGs(CGameState *gs)
{
	assert(!vstd::contains(gs->map->artInstances, art));
	assert(!art->getParentNodes().size());
	assert(art->artType);

	art->setType(art->artType);
	if(art->isCombined())
	{
		for(const auto & part : art->artType->getConstituents())
			art->addPart(ArtifactUtils::createNewArtifactInstance(part), ArtifactPosition::PRE_FIRST);
	}
	gs->map->addNewArtifactInstance(art);
}

const CStackInstance * StackLocation::getStack()
{
	if(!army->hasStackAtSlot(slot))
	{
		logNetwork->warn("%s don't have a stack at slot %d", army->nodeName(), slot.getNum());
		return nullptr;
	}
	return &army->getStack(slot);
}

struct ObjectRetriever
{
	const CArmedInstance * operator()(const ConstTransitivePtr<CGHeroInstance> &h) const
	{
		return h;
	}
	const CArmedInstance * operator()(const ConstTransitivePtr<CStackInstance> &s) const
	{
		return s->armyObj;
	}
};
template<typename T>
struct GetBase
{
	template <typename TArg>
	T * operator()(TArg &arg) const
	{
		return arg;
	}
};

void ChangeStackCount::applyGs(CGameState * gs)
{
	auto * srcObj = gs->getArmyInstance(army);
	if(!srcObj)
		throw std::runtime_error("ChangeStackCount: invalid army object " + std::to_string(army.getNum()) + ", possible game state corruption.");

	if(absoluteValue)
		srcObj->setStackCount(slot, count);
	else
		srcObj->changeStackCount(slot, count);
}

void SetStackType::applyGs(CGameState * gs)
{
	auto * srcObj = gs->getArmyInstance(army);
	if(!srcObj)
		throw std::runtime_error("SetStackType: invalid army object " + std::to_string(army.getNum()) + ", possible game state corruption.");

	srcObj->setStackType(slot, type);
}

void EraseStack::applyGs(CGameState * gs)
{
	auto * srcObj = gs->getArmyInstance(army);
	if(!srcObj)
		throw std::runtime_error("EraseStack: invalid army object " + std::to_string(army.getNum()) + ", possible game state corruption.");

	srcObj->eraseStack(slot);
}

void SwapStacks::applyGs(CGameState * gs)
{
	auto * srcObj = gs->getArmyInstance(srcArmy);
	if(!srcObj)
		throw std::runtime_error("SwapStacks: invalid army object " + std::to_string(srcArmy.getNum()) + ", possible game state corruption.");

	auto * dstObj = gs->getArmyInstance(dstArmy);
	if(!dstObj)
		throw std::runtime_error("SwapStacks: invalid army object " + std::to_string(dstArmy.getNum()) + ", possible game state corruption.");

	CStackInstance * s1 = srcObj->detachStack(srcSlot);
	CStackInstance * s2 = dstObj->detachStack(dstSlot);

	srcObj->putStack(srcSlot, s2);
	dstObj->putStack(dstSlot, s1);
}

void InsertNewStack::applyGs(CGameState *gs)
{
	if(auto * obj = gs->getArmyInstance(army))
		obj->putStack(slot, new CStackInstance(type, count));
	else
		throw std::runtime_error("InsertNewStack: invalid army object " + std::to_string(army.getNum()) + ", possible game state corruption.");
}

void RebalanceStacks::applyGs(CGameState * gs)
{
	auto * srcObj = gs->getArmyInstance(srcArmy);
	if(!srcObj)
		throw std::runtime_error("RebalanceStacks: invalid army object " + std::to_string(srcArmy.getNum()) + ", possible game state corruption.");

	auto * dstObj = gs->getArmyInstance(dstArmy);
	if(!dstObj)
		throw std::runtime_error("RebalanceStacks: invalid army object " + std::to_string(dstArmy.getNum()) + ", possible game state corruption.");

	StackLocation src(srcObj, srcSlot);
	StackLocation dst(dstObj, dstSlot);

	const CCreature * srcType = src.army->getCreature(src.slot);
	TQuantity srcCount = src.army->getStackCount(src.slot);
	bool stackExp = VLC->settings()->getBoolean(EGameSettings::MODULE_STACK_EXPERIENCE);

	if(srcCount == count) //moving whole stack
	{
		const auto c = dst.army->getCreature(dst.slot);

		if(c) //stack at dest -> merge
		{
			assert(c == srcType);
			
			const auto srcHero = dynamic_cast<CGHeroInstance*>(src.army.get());
			const auto dstHero = dynamic_cast<CGHeroInstance*>(dst.army.get());
			auto srcStack = const_cast<CStackInstance*>(src.getStack());
			auto dstStack = const_cast<CStackInstance*>(dst.getStack());
			if(auto srcArt = srcStack->getArt(ArtifactPosition::CREATURE_SLOT))
			{
				if(auto dstArt = dstStack->getArt(ArtifactPosition::CREATURE_SLOT))
				{
					auto dstSlot = ArtifactUtils::getArtBackpackPosition(srcHero, dstArt->getTypeId());
					if(srcHero && dstSlot != ArtifactPosition::PRE_FIRST)
					{
						dstArt->move(*dstStack, ArtifactPosition::CREATURE_SLOT, *srcHero, dstSlot);
					}
					//else - artifact can be lost :/
					else
					{
						EraseArtifact ea;
						ea.al = ArtifactLocation(dstHero->id, ArtifactPosition::CREATURE_SLOT);
						ea.al.creature = dst.slot;
						ea.applyGs(gs);
						logNetwork->warn("Cannot move artifact! No free slots");
					}
					srcArt->move(*srcStack, ArtifactPosition::CREATURE_SLOT, *dstStack, ArtifactPosition::CREATURE_SLOT);
					//TODO: choose from dialog
				}
				else //just move to the other slot before stack gets erased
				{
					srcArt->move(*srcStack, ArtifactPosition::CREATURE_SLOT, *dstStack, ArtifactPosition::CREATURE_SLOT);
				}
			}
			if (stackExp)
			{
				ui64 totalExp = srcCount * src.army->getStackExperience(src.slot) + dst.army->getStackCount(dst.slot) * dst.army->getStackExperience(dst.slot);
				src.army->eraseStack(src.slot);
				dst.army->changeStackCount(dst.slot, count);
				dst.army->setStackExp(dst.slot, totalExp /(dst.army->getStackCount(dst.slot))); //mean
			}
			else
			{
				src.army->eraseStack(src.slot);
				dst.army->changeStackCount(dst.slot, count);
			}
		}
		else //move stack to an empty slot, no exp change needed
		{
			CStackInstance *stackDetached = src.army->detachStack(src.slot);
			dst.army->putStack(dst.slot, stackDetached);
		}
	}
	else
	{
		[[maybe_unused]] const CCreature *c = dst.army->getCreature(dst.slot);
		if(c) //stack at dest -> rebalance
		{
			assert(c == srcType);
			if (stackExp)
			{
				ui64 totalExp = srcCount * src.army->getStackExperience(src.slot) + dst.army->getStackCount(dst.slot) * dst.army->getStackExperience(dst.slot);
				src.army->changeStackCount(src.slot, -count);
				dst.army->changeStackCount(dst.slot, count);
				dst.army->setStackExp(dst.slot, totalExp /(src.army->getStackCount(src.slot) + dst.army->getStackCount(dst.slot))); //mean
			}
			else
			{
				src.army->changeStackCount(src.slot, -count);
				dst.army->changeStackCount(dst.slot, count);
			}
		}
		else //split stack to an empty slot
		{
			src.army->changeStackCount(src.slot, -count);
			dst.army->addToSlot(dst.slot, srcType->getId(), count, false);
			if (stackExp)
				dst.army->setStackExp(dst.slot, src.army->getStackExperience(src.slot));
		}
	}

	CBonusSystemNode::treeHasChanged();
}

void BulkRebalanceStacks::applyGs(CGameState * gs)
{
	for(auto & move : moves)
		move.applyGs(gs);
}

void BulkSmartRebalanceStacks::applyGs(CGameState * gs)
{
	for(auto & move : moves)
		move.applyGs(gs);

	for(auto & change : changes)
		change.applyGs(gs);
}

void PutArtifact::applyGs(CGameState *gs)
{
	// Ensure that artifact has been correctly added via NewArtifact pack
	assert(vstd::contains(gs->map->artInstances, art));
	assert(!art->getParentNodes().empty());
	auto hero = gs->getHero(al.artHolder);
	assert(hero);
	assert(art && art->canBePutAt(hero, al.slot));
	art->putAt(*hero, al.slot);
}

void EraseArtifact::applyGs(CGameState *gs)
{
	const auto artSet = gs->getArtSet(al.artHolder);
	assert(artSet);
	const auto slot = artSet->getSlot(al.slot);
	if(slot->locked)
	{
		logGlobal->debug("Erasing locked artifact: %s", slot->artifact->artType->getNameTranslated());
		DisassembledArtifact dis;
		dis.al.artHolder = al.artHolder;
		
		for(auto & slotInfo : artSet->artifactsWorn)
		{
			auto art = slotInfo.second.artifact;
			if(art->isCombined() && art->isPart(slot->artifact))
			{
				dis.al.slot = artSet->getArtPos(art);
				break;
			}
		}
		assert((dis.al.slot != ArtifactPosition::PRE_FIRST) && "Failed to determine the assembly this locked artifact belongs to");
		logGlobal->debug("Found the corresponding assembly: %s", artSet->getArt(dis.al.slot)->artType->getNameTranslated());
		dis.applyGs(gs);
	}
	else
	{
		logGlobal->debug("Erasing artifact %s", slot->artifact->artType->getNameTranslated());
	}
	auto art = artSet->getArt(al.slot);
	assert(art);
	art->removeFrom(*artSet, al.slot);
}

void BulkMoveArtifacts::applyGs(CGameState * gs)
{
	const auto bulkArtsRemove = [](std::vector<LinkedSlots> & artsPack, CArtifactSet & artSet)
	{
		std::vector<ArtifactPosition> packToRemove;
		for(const auto & slotsPair : artsPack)
			packToRemove.push_back(slotsPair.srcPos);
		std::sort(packToRemove.begin(), packToRemove.end(), [](const ArtifactPosition & slot0, const ArtifactPosition & slot1) -> bool
			{
				return slot0.num > slot1.num;
			});

		for(const auto & slot : packToRemove)
		{
			auto * art = artSet.getArt(slot);
			assert(art);
			art->removeFrom(artSet, slot);
		}
	};

	const auto bulkArtsPut = [](std::vector<LinkedSlots> & artsPack, CArtifactSet & initArtSet, CArtifactSet & dstArtSet)
	{
		for(const auto & slotsPair : artsPack)
		{
			auto * art = initArtSet.getArt(slotsPair.srcPos);
			assert(art);
			art->putAt(dstArtSet, slotsPair.dstPos);
		}
	};
	
	auto * leftSet = gs->getArtSet(ArtifactLocation(srcArtHolder, srcCreature));
	assert(leftSet);
	auto * rightSet = gs->getArtSet(ArtifactLocation(dstArtHolder, dstCreature));
	assert(rightSet);
	CArtifactFittingSet artInitialSetLeft(*leftSet);
	bulkArtsRemove(artsPack0, *leftSet);
	if(!artsPack1.empty())
	{
		CArtifactFittingSet artInitialSetRight(*rightSet);
		bulkArtsRemove(artsPack1, *rightSet);
		bulkArtsPut(artsPack1, artInitialSetRight, *leftSet);
	}
	bulkArtsPut(artsPack0, artInitialSetLeft, *rightSet);
}

void AssembledArtifact::applyGs(CGameState *gs)
{
	auto hero = gs->getHero(al.artHolder);
	assert(hero);
	const auto transformedArt = hero->getArt(al.slot);
	assert(transformedArt);
	assert(vstd::contains_if(ArtifactUtils::assemblyPossibilities(hero, transformedArt->getTypeId()), [=](const CArtifact * art)->bool
		{
			return art->getId() == builtArt->getId();
		}));

	const auto transformedArtSlot = hero->getArtPos(transformedArt);
	auto * combinedArt = new CArtifactInstance(builtArt);
	gs->map->addNewArtifactInstance(combinedArt);

	// Find slots for all involved artifacts
	std::vector<ArtifactPosition> slotsInvolved;
	for(const auto constituent : builtArt->getConstituents())
	{
		ArtifactPosition slot;
		if(transformedArt->getTypeId() == constituent->getId())
			slot = transformedArtSlot;
		else
			slot = hero->getArtPos(constituent->getId(), false, false);

		assert(slot != ArtifactPosition::PRE_FIRST);
		slotsInvolved.emplace_back(slot);
	}
	std::sort(slotsInvolved.begin(), slotsInvolved.end(), std::greater<>());

	// Find a slot for combined artifact
	al.slot = transformedArtSlot;
	for(const auto slot : slotsInvolved)
	{
		if(ArtifactUtils::isSlotEquipment(transformedArtSlot))
		{

			if(ArtifactUtils::isSlotBackpack(slot))
			{
				al.slot = ArtifactPosition::BACKPACK_START;
				break;
			}

			if(!vstd::contains(combinedArt->artType->getPossibleSlots().at(hero->bearerType()), al.slot)
				&& vstd::contains(combinedArt->artType->getPossibleSlots().at(hero->bearerType()), slot))
				al.slot = slot;
		}
		else
		{
			if(ArtifactUtils::isSlotBackpack(slot))
				al.slot = std::min(al.slot, slot);
		}
	}

	// Delete parts from hero
	for(const auto slot : slotsInvolved)
	{
		const auto constituentInstance = hero->getArt(slot);
		constituentInstance->removeFrom(*hero, slot);

		if(ArtifactUtils::isSlotEquipment(al.slot) && slot != al.slot)
			combinedArt->addPart(constituentInstance, slot);
		else
			combinedArt->addPart(constituentInstance, ArtifactPosition::PRE_FIRST);
	}

	// Put new combined artifacts
	combinedArt->putAt(*hero, al.slot);
}

void DisassembledArtifact::applyGs(CGameState *gs)
{
	auto hero = gs->getHero(al.artHolder);
	assert(hero);
	auto disassembledArt = hero->getArt(al.slot);
	assert(disassembledArt);

	auto parts = disassembledArt->getPartsInfo();
	disassembledArt->removeFrom(*hero, al.slot);
	for(auto & part : parts)
	{
		// ArtifactPosition::PRE_FIRST is value of main part slot -> it'll replace combined artifact in its pos
		auto slot = (ArtifactUtils::isSlotEquipment(part.slot) ? part.slot : al.slot);
		disassembledArt->detachFrom(*part.art);
		part.art->putAt(*hero, slot);
	}
	gs->map->eraseArtifactInstance(disassembledArt);
}

void HeroVisit::applyGs(CGameState *gs)
{
}

void SetAvailableArtifacts::applyGs(CGameState * gs) const
{
	if(id != ObjectInstanceID::NONE)
	{
		if(auto * bm = dynamic_cast<CGBlackMarket *>(gs->getObjInstance(id)))
		{
			bm->artifacts = arts;
		}
		else
		{
			logNetwork->error("Wrong black market id!");
		}
	}
	else
	{
		gs->map->townMerchantArtifacts = arts;
	}
}

void NewTurn::applyGs(CGameState *gs)
{
	gs->day = day;

	// Update bonuses before doing anything else so hero don't get more MP than needed
	gs->globalEffects.removeBonusesRecursive(Bonus::OneDay); //works for children -> all game objs
	gs->globalEffects.reduceBonusDurations(Bonus::NDays);
	gs->globalEffects.reduceBonusDurations(Bonus::OneWeek);
	//TODO not really a single root hierarchy, what about bonuses placed elsewhere? [not an issue with H3 mechanics but in the future...]

	for(const NewTurn::Hero & h : heroes) //give mana/movement point
	{
		CGHeroInstance *hero = gs->getHero(h.id);
		if(!hero)
		{
			logGlobal->error("Hero %d not found in NewTurn::applyGs", h.id.getNum());
			continue;
		}

		hero->setMovementPoints(h.move);
		hero->mana = h.mana;
	}

	gs->heroesPool->onNewDay();

	for(const auto & re : res)
	{
		assert(re.first.isValidPlayer());
		gs->getPlayerState(re.first)->resources = re.second;
		gs->getPlayerState(re.first)->resources.amin(GameConstants::PLAYER_RESOURCES_CAP);
	}

	for(const auto & creatureSet : cres) //set available creatures in towns
		creatureSet.second.applyGs(gs);

	for(CGTownInstance* t : gs->map->towns)
		t->built = 0;

	if(gs->getDate(Date::DAY_OF_WEEK) == 1)
		gs->updateRumor();
}

void SetObjectProperty::applyGs(CGameState * gs) const
{
	CGObjectInstance *obj = gs->getObjInstance(id);
	if(!obj)
	{
		logNetwork->error("Wrong object ID - property cannot be set!");
		return;
	}

	auto * cai = dynamic_cast<CArmedInstance *>(obj);
	if(what == ObjProperty::OWNER && cai)
	{
		if(obj->ID == Obj::TOWN)
		{
			auto * t = dynamic_cast<CGTownInstance *>(obj);
			assert(t);

			PlayerColor oldOwner = t->tempOwner;
			if(oldOwner.isValidPlayer())
			{
				auto * state = gs->getPlayerState(oldOwner);
				state->towns -= t;

				if(state->towns.empty())
					state->daysWithoutCastle = 0;
			}
			if(identifier.as<PlayerColor>().isValidPlayer())
			{
				PlayerState * p = gs->getPlayerState(identifier.as<PlayerColor>());
				p->towns.emplace_back(t);

				//reset counter before NewTurn to avoid no town message if game loaded at turn when one already captured
				if(p->daysWithoutCastle)
					p->daysWithoutCastle = std::nullopt;
			}
		}

		CBonusSystemNode & nodeToMove = cai->whatShouldBeAttached();
		nodeToMove.detachFrom(cai->whereShouldBeAttached(gs));
		obj->setProperty(what, identifier);
		nodeToMove.attachTo(cai->whereShouldBeAttached(gs));
	}
	else //not an armed instance
	{
		obj->setProperty(what, identifier);
	}
}

void HeroLevelUp::applyGs(CGameState * gs) const
{
	auto * hero = gs->getHero(heroId);
	assert(hero);
	hero->levelUp(skills);
}

void CommanderLevelUp::applyGs(CGameState * gs) const
{
	auto * hero = gs->getHero(heroId);
	assert(hero);
	auto commander = hero->commander;
	assert(commander);
	commander->levelUp();
}

void BattleStart::applyGs(CGameState * gs) const
{
	assert(battleID == gs->nextBattleID);

	gs->currentBattles.emplace_back(info);

	info->battleID = gs->nextBattleID;
	info->localInit();

	gs->nextBattleID = BattleID(gs->nextBattleID.getNum() + 1);
}

void BattleNextRound::applyGs(CGameState * gs) const
{
	gs->getBattle(battleID)->nextRound();
}

void BattleSetActiveStack::applyGs(CGameState * gs) const
{
	gs->getBattle(battleID)->nextTurn(stack);
}

void BattleTriggerEffect::applyGs(CGameState * gs) const
{
	CStack * st = gs->getBattle(battleID)->getStack(stackID);
	assert(st);
	switch(static_cast<BonusType>(effect))
	{
	case BonusType::HP_REGENERATION:
	{
		int64_t toHeal = val;
		st->heal(toHeal, EHealLevel::HEAL, EHealPower::PERMANENT);
		break;
	}
	case BonusType::MANA_DRAIN:
	{
		CGHeroInstance * h = gs->getHero(ObjectInstanceID(additionalInfo));
		st->drainedMana = true;
		h->mana -= val;
		vstd::amax(h->mana, 0);
		break;
	}
	case BonusType::POISON:
	{
		auto b = st->getLocalBonus(Selector::source(BonusSource::SPELL_EFFECT, SpellID(SpellID::POISON))
				.And(Selector::type()(BonusType::STACK_HEALTH)));
		if (b)
			b->val = val;
		break;
	}
	case BonusType::ENCHANTER:
	case BonusType::MORALE:
		break;
	case BonusType::FEAR:
		st->fear = true;
		break;
	default:
		logNetwork->error("Unrecognized trigger effect type %d", effect);
	}
}

void BattleUpdateGateState::applyGs(CGameState * gs) const
{
	if(gs->getBattle(battleID))
		gs->getBattle(battleID)->si.gateState = state;
}

void BattleCancelled::applyGs(CGameState * gs) const
{
	auto currentBattle = boost::range::find_if(gs->currentBattles, [&](const auto & battle)
	{
		return battle->battleID == battleID;
	});

	assert(currentBattle != gs->currentBattles.end());
	gs->currentBattles.erase(currentBattle);
}

void BattleResultAccepted::applyGs(CGameState * gs) const
{
	// Remove any "until next battle" bonuses
	for(auto & res : heroResult)
	{
		if(res.hero)
			res.hero->removeBonusesRecursive(Bonus::OneBattle);
	}

	if(winnerSide != 2)
	{
		// Grow up growing artifacts
		const auto hero = heroResult[winnerSide].hero;

		if (hero)
		{
			if(hero->commander && hero->commander->alive)
			{
				for(auto & art : hero->commander->artifactsWorn)
					art.second.artifact->growingUp();
			}
			for(auto & art : hero->artifactsWorn)
			{
				art.second.artifact->growingUp();
			}
		}
	}

	if(VLC->settings()->getBoolean(EGameSettings::MODULE_STACK_EXPERIENCE))
	{
		if(heroResult[0].army)
			heroResult[0].army->giveStackExp(heroResult[0].exp);
		if(heroResult[1].army)
			heroResult[1].army->giveStackExp(heroResult[1].exp);
		CBonusSystemNode::treeHasChanged();
	}

	auto currentBattle = boost::range::find_if(gs->currentBattles, [&](const auto & battle)
	{
		return battle->battleID == battleID;
	});

	assert(currentBattle != gs->currentBattles.end());
	gs->currentBattles.erase(currentBattle);
}

void BattleLogMessage::applyGs(CGameState *gs)
{
	//nothing
}

void BattleLogMessage::applyBattle(IBattleState * battleState)
{
	//nothing
}

void BattleStackMoved::applyGs(CGameState *gs)
{
	applyBattle(gs->getBattle(battleID));
}

void BattleStackMoved::applyBattle(IBattleState * battleState)
{
	battleState->moveUnit(stack, tilesToMove.back());
}

void BattleStackAttacked::applyGs(CGameState * gs)
{
	applyBattle(gs->getBattle(battleID));
}

void BattleStackAttacked::applyBattle(IBattleState * battleState)
{
	battleState->setUnitState(newState.id, newState.data, newState.healthDelta);
}

void BattleAttack::applyGs(CGameState * gs)
{
	CStack * attacker = gs->getBattle(battleID)->getStack(stackAttacking);
	assert(attacker);

	attackerChanges.applyGs(gs);

	for(BattleStackAttacked & stackAttacked : bsa)
		stackAttacked.applyGs(gs);

	attacker->removeBonusesRecursive(Bonus::UntilAttack);

	if(!this->counter())
		attacker->removeBonusesRecursive(Bonus::UntilOwnAttack);
}

void StartAction::applyGs(CGameState *gs)
{
	CStack *st = gs->getBattle(battleID)->getStack(ba.stackNumber);

	if(ba.actionType == EActionType::END_TACTIC_PHASE)
	{
		gs->getBattle(battleID)->tacticDistance = 0;
		return;
	}

	if(gs->getBattle(battleID)->tacticDistance)
	{
		// moves in tactics phase do not affect creature status
		// (tactics stack queue is managed by client)
		return;
	}

	if (ba.isUnitAction())
	{
		assert(st); // stack must exists for all non-hero actions

		switch(ba.actionType)
		{
			case EActionType::DEFEND:
				st->waiting = false;
				st->defending = true;
				st->defendingAnim = true;
				break;
			case EActionType::WAIT:
				st->defendingAnim = false;
				st->waiting = true;
				st->waitedThisTurn = true;
				break;
			case EActionType::HERO_SPELL: //no change in current stack state
				break;
			default: //any active stack action - attack, catapult, heal, spell...
				st->waiting = false;
				st->defendingAnim = false;
				st->movedThisRound = true;
				break;
		}
	}
	else
	{
		if(ba.actionType == EActionType::HERO_SPELL)
			gs->getBattle(battleID)->sides[ba.side].usedSpellsHistory.push_back(ba.spell);
	}
}

void BattleSpellCast::applyGs(CGameState * gs) const
{
	if(castByHero)
	{
		if(side < 2)
		{
			gs->getBattle(battleID)->sides[side].castSpellsCount++;
		}
	}
}

void SetStackEffect::applyGs(CGameState *gs)
{
	applyBattle(gs->getBattle(battleID));
}

void SetStackEffect::applyBattle(IBattleState * battleState)
{
	for(const auto & stackData : toRemove)
		battleState->removeUnitBonus(stackData.first, stackData.second);

	for(const auto & stackData : toUpdate)
		battleState->updateUnitBonus(stackData.first, stackData.second);

	for(const auto & stackData : toAdd)
		battleState->addUnitBonus(stackData.first, stackData.second);
}


void StacksInjured::applyGs(CGameState *gs)
{
	applyBattle(gs->getBattle(battleID));
}

void StacksInjured::applyBattle(IBattleState * battleState)
{
	for(BattleStackAttacked stackAttacked : stacks)
		stackAttacked.applyBattle(battleState);
}

void BattleUnitsChanged::applyGs(CGameState *gs)
{
	applyBattle(gs->getBattle(battleID));
}

void BattleUnitsChanged::applyBattle(IBattleState * battleState)
{
	for(auto & elem : changedStacks)
	{
		switch(elem.operation)
		{
		case BattleChanges::EOperation::RESET_STATE:
			battleState->setUnitState(elem.id, elem.data, elem.healthDelta);
			break;
		case BattleChanges::EOperation::REMOVE:
			battleState->removeUnit(elem.id);
			break;
		case BattleChanges::EOperation::ADD:
			battleState->addUnit(elem.id, elem.data);
			break;
		case BattleChanges::EOperation::UPDATE:
			battleState->updateUnit(elem.id, elem.data);
			break;
		default:
			logNetwork->error("Unknown unit operation %d", static_cast<int>(elem.operation));
			break;
		}
	}
}

void BattleObstaclesChanged::applyGs(CGameState * gs)
{
	applyBattle(gs->getBattle(battleID));
}

void BattleObstaclesChanged::applyBattle(IBattleState * battleState)
{
	for(const auto & change : changes)
	{
		switch(change.operation)
		{
		case BattleChanges::EOperation::REMOVE:
			battleState->removeObstacle(change.id);
			break;
		case BattleChanges::EOperation::ADD:
			battleState->addObstacle(change);
			break;
		case BattleChanges::EOperation::UPDATE:
			battleState->updateObstacle(change);
			break;
		default:
			logNetwork->error("Unknown obstacle operation %d", static_cast<int>(change.operation));
			break;
		}
	}
}

CatapultAttack::CatapultAttack() = default;

CatapultAttack::~CatapultAttack() = default;

void CatapultAttack::applyGs(CGameState * gs)
{
	applyBattle(gs->getBattle(battleID));
}

void CatapultAttack::visitTyped(ICPackVisitor & visitor)
{
	visitor.visitCatapultAttack(*this);
}

void CatapultAttack::applyBattle(IBattleState * battleState)
{
	const auto * town = battleState->getDefendedTown();
	if(!town)
		return;

	if(town->fortLevel() == CGTownInstance::NONE)
		return;

	for(const auto & part : attackedParts)
	{
		auto newWallState = SiegeInfo::applyDamage(battleState->getWallState(part.attackedPart), part.damageDealt);
		battleState->setWallState(part.attackedPart, newWallState);
	}
}

void BattleSetStackProperty::applyGs(CGameState * gs) const
{
	CStack * stack = gs->getBattle(battleID)->getStack(stackID, false);
	switch(which)
	{
		case CASTS:
		{
			if(absolute)
				logNetwork->error("Can not change casts in absolute mode");
			else
				stack->casts.use(-val);
			break;
		}
		case ENCHANTER_COUNTER:
		{
			auto & counter = gs->getBattle(battleID)->sides[gs->getBattle(battleID)->whatSide(stack->unitOwner())].enchanterCounter;
			if(absolute)
				counter = val;
			else
				counter += val;
			vstd::amax(counter, 0);
			break;
		}
		case UNBIND:
		{
			stack->removeBonusesRecursive(Selector::type()(BonusType::BIND_EFFECT));
			break;
		}
		case CLONED:
		{
			stack->cloned = true;
			break;
		}
		case HAS_CLONE:
		{
			stack->cloneID = val;
			break;
		}
	}
}

void PlayerCheated::applyGs(CGameState * gs) const
{
	if(!player.isValidPlayer())
		return;

	gs->getPlayerState(player)->enteredLosingCheatCode = losingCheatCode;
	gs->getPlayerState(player)->enteredWinningCheatCode = winningCheatCode;
	gs->getPlayerState(player)->cheated = true;
}

void PlayerStartsTurn::applyGs(CGameState * gs) const
{
	//assert(gs->actingPlayers.count(player) == 0);//Legal - may happen after loading of deserialized map state
	gs->actingPlayers.insert(player);
}

void PlayerEndsTurn::applyGs(CGameState * gs) const
{
	assert(gs->actingPlayers.count(player) == 1);
	gs->actingPlayers.erase(player);
}

void DaysWithoutTown::applyGs(CGameState * gs) const
{
	auto & playerState = gs->players[player];
	playerState.daysWithoutCastle = daysWithoutCastle;
}

void TurnTimeUpdate::applyGs(CGameState *gs) const
{
	auto & playerState = gs->players[player];
	playerState.turnTimer = turnTimer;
}

void EntitiesChanged::applyGs(CGameState * gs)
{
	for(const auto & change : changes)
		gs->updateEntity(change.metatype, change.entityIndex, change.data);
}

const CArtifactInstance * ArtSlotInfo::getArt() const
{
	if(locked)
	{
		logNetwork->warn("ArtifactLocation::getArt: This location is locked!");
		return nullptr;
	}
	return artifact;
}

VCMI_LIB_NAMESPACE_END
