#include "TrialThree.h"

bool TrialThree(Game game, Player player) {
    Attacks enemyAttacks = player.GetCharacterAttacks(); // Copy player's attacks and give enemy shadow name
    string enemyName = "Shadow " + player.GetName();

    Player enemy(enemyName, player.GetMaxHealth(), player.GetAttackDamage(), player.GetCooldown(), player.GetPlayerChoice(), enemyAttacks);

    return game.StoryModeFight(player, enemy); // return true or false for the worthiness meter thing
}
