//
//  GameNotifier.cpp
//  FirstAdventure
//
//  Created by David Paris on 28/01/2018.
//  Copyright © 2018 David Paris. All rights reserved.
//

#include "GameNotifier.hpp"

void GameNotifier::onNotify(Notifier::Message message)
{
    game_->handleMessage(message);
}
