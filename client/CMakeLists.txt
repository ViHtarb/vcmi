set(client_SRCS
	StdInc.cpp
	../CCallback.cpp

	adventureMap/AdventureMapInterface.cpp
	adventureMap/AdventureMapShortcuts.cpp
	adventureMap/AdventureMapWidget.cpp
	adventureMap/AdventureOptions.cpp
	adventureMap/CInGameConsole.cpp
	adventureMap/CInfoBar.cpp
	adventureMap/CList.cpp
	adventureMap/CMinimap.cpp
	adventureMap/CResDataBar.cpp
	adventureMap/MapAudioPlayer.cpp
	adventureMap/TurnTimerWidget.cpp

	battle/BattleActionsController.cpp
	battle/BattleAnimationClasses.cpp
	battle/BattleEffectsController.cpp
	battle/BattleFieldController.cpp
	battle/BattleInterface.cpp
	battle/BattleInterfaceClasses.cpp
	battle/BattleObstacleController.cpp
	battle/BattleProjectileController.cpp
	battle/BattleRenderer.cpp
	battle/BattleSiegeController.cpp
	battle/BattleStacksController.cpp
	battle/BattleWindow.cpp
	battle/CreatureAnimation.cpp

	eventsSDL/NotificationHandler.cpp
	eventsSDL/InputHandler.cpp
	eventsSDL/InputSourceKeyboard.cpp
	eventsSDL/InputSourceMouse.cpp
	eventsSDL/InputSourceText.cpp
	eventsSDL/InputSourceTouch.cpp
	eventsSDL/InputSourceGameController.cpp

	gui/CGuiHandler.cpp
	gui/CIntObject.cpp
	gui/CursorHandler.cpp
	gui/EventDispatcher.cpp
	gui/EventsReceiver.cpp
	gui/InterfaceObjectConfigurable.cpp
	gui/FramerateManager.cpp
	gui/ShortcutHandler.cpp
	gui/WindowHandler.cpp

	lobby/CBonusSelection.cpp
	lobby/CCampaignInfoScreen.cpp
	lobby/CLobbyScreen.cpp
	lobby/CSavingScreen.cpp
	lobby/CScenarioInfoScreen.cpp
	lobby/CSelectionBase.cpp
	lobby/TurnOptionsTab.cpp
	lobby/ExtraOptionsTab.cpp
	lobby/OptionsTab.cpp
	lobby/OptionsTabBase.cpp
	lobby/RandomMapTab.cpp
	lobby/SelectionTab.cpp

	mainmenu/CCampaignScreen.cpp
	mainmenu/CMainMenu.cpp
	mainmenu/CPrologEpilogVideo.cpp
	mainmenu/CreditsScreen.cpp
	mainmenu/CHighScoreScreen.cpp

	mapView/MapRenderer.cpp
	mapView/MapRendererContext.cpp
	mapView/MapRendererContextState.cpp
	mapView/MapView.cpp
	mapView/MapViewActions.cpp
	mapView/MapViewCache.cpp
	mapView/MapViewController.cpp
	mapView/MapViewModel.cpp
	mapView/mapHandler.cpp

	media/CAudioBase.cpp
	media/CMusicHandler.cpp
	media/CSoundHandler.cpp
	media/CVideoHandler.cpp

	render/CAnimation.cpp
	render/CBitmapHandler.cpp
	render/CDefFile.cpp
	render/Canvas.cpp
	render/ColorFilter.cpp
	render/Colors.cpp
	render/Graphics.cpp
	render/IFont.cpp

	renderSDL/CBitmapFont.cpp
	renderSDL/CBitmapHanFont.cpp
	renderSDL/CTrueTypeFont.cpp
	renderSDL/CursorHardware.cpp
	renderSDL/CursorSoftware.cpp
	renderSDL/RenderHandler.cpp
	renderSDL/SDLImage.cpp
	renderSDL/SDLImageLoader.cpp
	renderSDL/SDLRWwrapper.cpp
	renderSDL/ScreenHandler.cpp
	renderSDL/SDL_Extensions.cpp

	globalLobby/GlobalLobbyClient.cpp
	globalLobby/GlobalLobbyInviteWindow.cpp
	globalLobby/GlobalLobbyLoginWindow.cpp
	globalLobby/GlobalLobbyRoomWindow.cpp
	globalLobby/GlobalLobbyServerSetup.cpp
	globalLobby/GlobalLobbyWidget.cpp
	globalLobby/GlobalLobbyWindow.cpp

	widgets/Buttons.cpp
	widgets/CArtPlace.cpp
	widgets/CComponent.cpp
	widgets/CExchangeController.cpp
	widgets/CGarrisonInt.cpp
	widgets/CreatureCostBox.cpp
	widgets/ComboBox.cpp
	widgets/CTextInput.cpp
	widgets/GraphicalPrimitiveCanvas.cpp
	widgets/Images.cpp
	widgets/MiscWidgets.cpp
	widgets/ObjectLists.cpp
	widgets/TextControls.cpp
	widgets/Scrollable.cpp
	widgets/Slider.cpp
	widgets/CArtifactsOfHeroBase.cpp
	widgets/CArtifactsOfHeroMain.cpp
	widgets/CArtifactsOfHeroKingdom.cpp
	widgets/CArtifactsOfHeroAltar.cpp
	widgets/CArtifactsOfHeroMarket.cpp
	widgets/CArtifactsOfHeroBackpack.cpp
	widgets/RadialMenu.cpp
	widgets/VideoWidget.cpp
	widgets/markets/CAltarArtifacts.cpp
	widgets/markets/CAltarCreatures.cpp
	widgets/markets/CArtifactsBuying.cpp
	widgets/markets/CArtifactsSelling.cpp
	widgets/markets/CFreelancerGuild.cpp
	widgets/markets/CMarketResources.cpp
	widgets/markets/CTransferResources.cpp
	widgets/markets/CMarketBase.cpp
	widgets/markets/TradePanels.cpp

	windows/CCastleInterface.cpp
	windows/CCreatureWindow.cpp
	windows/CExchangeWindow.cpp
	windows/CHeroOverview.cpp
	windows/CHeroWindow.cpp
	windows/CKingdomInterface.cpp
	windows/CMapOverview.cpp
	windows/CMarketWindow.cpp
	windows/CMessage.cpp
	windows/CPuzzleWindow.cpp
	windows/CQuestLog.cpp
	windows/CSpellWindow.cpp
	windows/CTutorialWindow.cpp
	windows/CWindowObject.cpp
	windows/CreaturePurchaseCard.cpp
	windows/GUIClasses.cpp
	windows/InfoWindows.cpp
	windows/QuickRecruitmentWindow.cpp
	windows/CHeroBackpackWindow.cpp
	windows/CWindowWithArtifacts.cpp
	windows/settings/GeneralOptionsTab.cpp
	windows/settings/OtherOptionsTab.cpp
	windows/settings/SettingsMainWindow.cpp
	windows/settings/BattleOptionsTab.cpp
	windows/settings/AdventureOptionsTab.cpp

	ArtifactsUIController.cpp
	CGameInfo.cpp
	CMT.cpp
	CPlayerInterface.cpp
	PlayerLocalState.cpp
	CServerHandler.cpp
	Client.cpp
	ClientCommandManager.cpp
	GameChatHandler.cpp
	HeroMovementController.cpp
	NetPacksClient.cpp
	NetPacksLobbyClient.cpp
	ServerRunner.cpp
)

set(client_HEADERS
	StdInc.h

	adventureMap/AdventureMapInterface.h
	adventureMap/AdventureMapShortcuts.h
	adventureMap/AdventureMapWidget.h
	adventureMap/AdventureState.h
	adventureMap/AdventureOptions.h
	adventureMap/CInGameConsole.h
	adventureMap/CInfoBar.h
	adventureMap/CList.h
	adventureMap/CMinimap.h
	adventureMap/CResDataBar.h
	adventureMap/MapAudioPlayer.h
	adventureMap/TurnTimerWidget.h

	battle/BattleActionsController.h
	battle/BattleAnimationClasses.h
	battle/BattleConstants.h
	battle/BattleEffectsController.h
	battle/BattleFieldController.h
	battle/BattleInterface.h
	battle/BattleInterfaceClasses.h
	battle/BattleObstacleController.h
	battle/BattleProjectileController.h
	battle/BattleRenderer.h
	battle/BattleSiegeController.h
	battle/BattleStacksController.h
	battle/BattleWindow.h
	battle/CreatureAnimation.h

	eventsSDL/NotificationHandler.h
	eventsSDL/InputHandler.h
	eventsSDL/InputSourceKeyboard.h
	eventsSDL/InputSourceMouse.h
	eventsSDL/InputSourceText.h
	eventsSDL/InputSourceTouch.h
	eventsSDL/InputSourceGameController.h

	gui/CGuiHandler.h
	gui/CIntObject.h
	gui/CursorHandler.h
	gui/EventDispatcher.h
	gui/EventsReceiver.h
	gui/InterfaceObjectConfigurable.h
	gui/FramerateManager.h
	gui/MouseButton.h
	gui/Shortcut.h
	gui/ShortcutHandler.h
	gui/TextAlignment.h
	gui/WindowHandler.h

	lobby/CBonusSelection.h
	lobby/CCampaignInfoScreen.h
	lobby/CLobbyScreen.h
	lobby/CSavingScreen.h
	lobby/CScenarioInfoScreen.h
	lobby/CSelectionBase.h
	lobby/TurnOptionsTab.h
	lobby/ExtraOptionsTab.h
	lobby/OptionsTab.h
	lobby/OptionsTabBase.h
	lobby/RandomMapTab.h
	lobby/SelectionTab.h

	mainmenu/CCampaignScreen.h
	mainmenu/CMainMenu.h
	mainmenu/CPrologEpilogVideo.h
	mainmenu/CreditsScreen.h
	mainmenu/CHighScoreScreen.h

	mapView/IMapRendererContext.h
	mapView/IMapRendererObserver.h
	mapView/MapRenderer.h
	mapView/MapRendererContext.h
	mapView/MapRendererContextState.h
	mapView/MapView.h
	mapView/MapViewActions.h
	mapView/MapViewCache.h
	mapView/MapViewController.h
	mapView/MapViewModel.h
	mapView/mapHandler.h

	media/CAudioBase.h
	media/CEmptyVideoPlayer.h
	media/CMusicHandler.h
	media/CSoundHandler.h
	media/CVideoHandler.h
	media/IMusicPlayer.h
	media/ISoundPlayer.h
	media/IVideoPlayer.h

	render/CAnimation.h
	render/CBitmapHandler.h
	render/CDefFile.h
	render/Canvas.h
	render/ColorFilter.h
	render/Colors.h
	render/EFont.h
	render/Graphics.h
	render/ICursor.h
	render/IFont.h
	render/IImage.h
	render/IImageLoader.h
	render/IRenderHandler.h
	render/IScreenHandler.h

	renderSDL/CBitmapFont.h
	renderSDL/CBitmapHanFont.h
	renderSDL/CTrueTypeFont.h
	renderSDL/CursorHardware.h
	renderSDL/CursorSoftware.h
	renderSDL/RenderHandler.h
	renderSDL/SDLImage.h
	renderSDL/SDLImageLoader.h
	renderSDL/SDLRWwrapper.h
	renderSDL/ScreenHandler.h
	renderSDL/SDL_Extensions.h
	renderSDL/SDL_PixelAccess.h

	globalLobby/GlobalLobbyClient.h
	globalLobby/GlobalLobbyDefines.h
	globalLobby/GlobalLobbyInviteWindow.h
	globalLobby/GlobalLobbyLoginWindow.h
	globalLobby/GlobalLobbyRoomWindow.h
	globalLobby/GlobalLobbyServerSetup.h
	globalLobby/GlobalLobbyObserver.h
	globalLobby/GlobalLobbyWidget.h
	globalLobby/GlobalLobbyWindow.h

	widgets/Buttons.h
	widgets/CArtPlace.h
	widgets/CComponent.h
	widgets/CExchangeController.h
	widgets/CGarrisonInt.h
	widgets/CreatureCostBox.h
	widgets/ComboBox.h
	widgets/CTextInput.h
	widgets/GraphicalPrimitiveCanvas.h
	widgets/Images.h
	widgets/MiscWidgets.h
	widgets/ObjectLists.h
	widgets/TextControls.h
	widgets/Scrollable.h
	widgets/Slider.h
	widgets/CArtifactsOfHeroBase.h
	widgets/CArtifactsOfHeroMain.h
	widgets/CArtifactsOfHeroKingdom.h
	widgets/CArtifactsOfHeroAltar.h
	widgets/CArtifactsOfHeroMarket.h
	widgets/CArtifactsOfHeroBackpack.h
	widgets/RadialMenu.h
	widgets/VideoWidget.h
	widgets/markets/CAltarArtifacts.h
	widgets/markets/CAltarCreatures.h
	widgets/markets/CArtifactsBuying.h
	widgets/markets/CArtifactsSelling.h
	widgets/markets/CFreelancerGuild.h
	widgets/markets/CMarketResources.h
	widgets/markets/CTransferResources.h
	widgets/markets/CMarketBase.h
	widgets/markets/TradePanels.h

	windows/CCastleInterface.h
	windows/CCreatureWindow.h
	windows/CExchangeWindow.h
	windows/CHeroOverview.h
	windows/CHeroWindow.h
	windows/CKingdomInterface.h
	windows/CMessage.h
	windows/CMapOverview.h
	windows/CMarketWindow.h
	windows/CPuzzleWindow.h
	windows/CQuestLog.h
	windows/CSpellWindow.h
	windows/CTutorialWindow.h
	windows/CWindowObject.h
	windows/CreaturePurchaseCard.h
	windows/GUIClasses.h
	windows/InfoWindows.h
	windows/QuickRecruitmentWindow.h
	windows/CHeroBackpackWindow.h
	windows/CWindowWithArtifacts.h
	windows/settings/GeneralOptionsTab.h
	windows/settings/OtherOptionsTab.h
	windows/settings/SettingsMainWindow.h
	windows/settings/BattleOptionsTab.h
	windows/settings/AdventureOptionsTab.h

	ArtifactsUIController.h
	CGameInfo.h
	CMT.h
	CPlayerInterface.h
	PlayerLocalState.h
	CServerHandler.h
	Client.h
	ClientCommandManager.h
	ClientNetPackVisitors.h
	ConditionalWait.h
	HeroMovementController.h
	GameChatHandler.h
	LobbyClientNetPackVisitors.h
	ServerRunner.h
	resource.h
)

if(APPLE_IOS)
	set(client_SRCS ${client_SRCS}
		CFocusableHelper.cpp
		ios/GameChatKeyboardHandler.m
		ios/main.m
		ios/startSDL.mm
		ios/utils.mm
	)
	set(client_HEADERS ${client_HEADERS}
		CFocusableHelper.h
		ios/GameChatKeyboardHandler.h
		ios/startSDL.h
		ios/utils.h
	)
endif()

assign_source_group(${client_SRCS} ${client_HEADERS} VCMI_client.rc)

if(ANDROID)
	add_library(vcmiclient SHARED ${client_SRCS} ${client_HEADERS})
	set_target_properties(vcmiclient PROPERTIES
		OUTPUT_NAME "vcmiclient_${ANDROID_ABI}" # required by Qt
	)
else()
	add_executable(vcmiclient ${client_SRCS} ${client_HEADERS})
endif()

if(NOT ENABLE_STATIC_LIBS)
	add_dependencies(vcmiclient
		BattleAI
		EmptyAI
		StupidAI
		VCAI
	)
	if(ENABLE_NULLKILLER_AI)
		add_dependencies(vcmiclient Nullkiller)
	endif()
endif()
if(APPLE_IOS)
	if(ENABLE_ERM)
		add_dependencies(vcmiclient vcmiERM)
	endif()
	if(ENABLE_LUA)
		add_dependencies(vcmiclient vcmiLua)
	endif()
endif()

if(WIN32)
	target_sources(vcmiclient PRIVATE "VCMI_client.rc")
	set_target_properties(vcmiclient
		PROPERTIES
			OUTPUT_NAME "VCMI_client"
			PROJECT_LABEL "VCMI_client"
	)
	set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT vcmiclient)
	if(NOT ENABLE_DEBUG_CONSOLE)
		set_target_properties(vcmiclient PROPERTIES WIN32_EXECUTABLE)
		target_link_libraries(vcmiclient SDL2::SDL2main)
	endif()
	target_compile_definitions(vcmiclient PRIVATE WINDOWS_IGNORE_PACKING_MISMATCH)

# TODO: very hacky, find proper solution to copy AI dlls into bin dir
	if(MSVC)
		add_custom_command(TARGET vcmiclient POST_BUILD
			WORKING_DIRECTORY "$<TARGET_FILE_DIR:vcmiclient>"
			COMMAND ${CMAKE_COMMAND} -E copy AI/fuzzylite.dll fuzzylite.dll
			COMMAND ${CMAKE_COMMAND} -E copy AI/tbb12.dll tbb12.dll
		)
	endif()
elseif(APPLE_IOS)
	target_link_libraries(vcmiclient PRIVATE
		iOS_utils

		# FFmpeg
		bz2
		iconv
		z
		"-framework AudioToolbox"
		"-framework AVFoundation"
		"-framework CoreMedia"
		"-framework VideoToolbox"
	)

	set_target_properties(vcmiclient PROPERTIES
		MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_LIST_DIR}/ios/Info.plist"
		XCODE_ATTRIBUTE_LD_RUNPATH_SEARCH_PATHS "@executable_path/Frameworks"
		XCODE_ATTRIBUTE_CODE_SIGNING_ALLOWED "$(CODE_SIGNING_ALLOWED_FOR_APPS)"
		XCODE_ATTRIBUTE_ASSETCATALOG_COMPILER_APPICON_NAME AppIcon
	)

	foreach(XCODE_RESOURCE LaunchScreen.storyboard Images.xcassets Settings.bundle vcmi_logo.png)
		set(XCODE_RESOURCE_PATH ios/${XCODE_RESOURCE})
		target_sources(vcmiclient PRIVATE ${XCODE_RESOURCE_PATH})
		set_source_files_properties(${XCODE_RESOURCE_PATH} PROPERTIES MACOSX_PACKAGE_LOCATION Resources)

		# workaround to prevent CMAKE_SKIP_PRECOMPILE_HEADERS being added as compile flag
		if(CMAKE_VERSION VERSION_GREATER_EQUAL "3.22.0" AND CMAKE_VERSION VERSION_LESS "3.25.0")
			set_source_files_properties(${XCODE_RESOURCE_PATH} PROPERTIES LANGUAGE CXX)
		endif()
	endforeach()

	set(CMAKE_EXE_LINKER_FLAGS "-Wl,-e,_client_main")
endif()

target_link_libraries(vcmiclient PRIVATE vcmiservercommon)
if(ENABLE_SINGLE_APP_BUILD AND ENABLE_LAUNCHER)
	target_link_libraries(vcmiclient PRIVATE vcmilauncher)
endif()

target_link_libraries(vcmiclient PRIVATE
		vcmi SDL2::SDL2 SDL2::Image SDL2::Mixer SDL2::TTF
)

if(ffmpeg_LIBRARIES)
	target_link_libraries(vcmiclient PRIVATE
		${ffmpeg_LIBRARIES}
	)
else()
	target_compile_definitions(vcmiclient PRIVATE DISABLE_VIDEO)
endif()

target_include_directories(vcmiclient PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
)

if (ffmpeg_INCLUDE_DIRS)
	target_include_directories(vcmiclient PRIVATE
		${ffmpeg_INCLUDE_DIRS}
	)
endif()

vcmi_set_output_dir(vcmiclient "")
enable_pch(vcmiclient)

if(APPLE_IOS)
	vcmi_install_conan_deps("\${CMAKE_INSTALL_PREFIX}")
	add_custom_command(TARGET vcmiclient POST_BUILD
		COMMAND ios/set_build_version.sh "$<TARGET_BUNDLE_CONTENT_DIR:vcmiclient>"
		COMMAND ${CMAKE_COMMAND} --install "${CMAKE_BINARY_DIR}" --component "${CMAKE_INSTALL_DEFAULT_COMPONENT_NAME}" --config "$<CONFIG>" --prefix "$<TARGET_BUNDLE_CONTENT_DIR:vcmiclient>"
		COMMAND ios/rpath_remove_symlinks.sh
		COMMAND ios/codesign.sh
		WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
	)
	install(TARGETS vcmiclient DESTINATION Payload COMPONENT app) # for ipa generation with cpack
elseif(ANDROID)
	find_program(androidDeployQt androiddeployqt
		PATHS "${qtBinDir}"
	)
	vcmi_install_conan_deps("\${CMAKE_INSTALL_PREFIX}/${LIB_DIR}")

	add_custom_target(android_deploy ALL
		COMMAND ${CMAKE_COMMAND} --install "${CMAKE_BINARY_DIR}" --config "$<CONFIG>" --prefix "${androidQtBuildDir}"
		COMMAND "${androidDeployQt}" --input "${CMAKE_BINARY_DIR}/androiddeployqt.json" --output "${androidQtBuildDir}" --android-platform "android-${ANDROID_TARGET_SDK_VERSION}" --verbose $<$<NOT:$<CONFIG:Debug>>:--release> ${ANDROIDDEPLOYQT_OPTIONS}
		COMMAND_EXPAND_LISTS
		VERBATIM
		COMMENT "Create android package"
	)
	add_dependencies(android_deploy vcmiclient)
else()
	install(TARGETS vcmiclient DESTINATION ${BIN_DIR})
endif()

#install icons and desktop file on Linux
if(NOT WIN32 AND NOT APPLE AND NOT ANDROID)
	#FIXME: move to client makefile?
	foreach(iconSize 16 22 32 48 64 128 256 512 1024 2048)
		install(FILES "icons/vcmiclient.${iconSize}x${iconSize}.png"
			DESTINATION "share/icons/hicolor/${iconSize}x${iconSize}/apps"
			RENAME vcmiclient.png
		)
	endforeach()

	install(FILES icons/vcmiclient.svg
		DESTINATION share/icons/hicolor/scalable/apps
		RENAME vcmiclient.svg
	)
	install(FILES icons/vcmiclient.desktop
		DESTINATION share/applications
	)
endif()
