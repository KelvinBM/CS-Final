#include "TrialThree.h"

bool TrialThree(Game game, Player player) {
    Attacks enemyAttacks = player.GetCharacterAttacks();
    string enemyName = "Shadow " + player.GetName();

    Player enemy(enemyName, player.GetMaxHealth(), player.GetAttackDamage(), player.GetCooldown(), player.GetPlayerChoice(), enemyAttacks);

    return game.StoryModeFight(player, enemy);
}
