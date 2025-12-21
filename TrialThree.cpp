#include "TrialThree.h"

bool TrialThree(Game game, Player player) {
    // Copy attacks and stats, but give the enemy a distinct name so it's clear in output
    Attacks enemyAttacks = player.GetCharacterAttacks();
    string enemyName = "Shadow " + player.GetName();

    Player enemy(enemyName, player.GetMaxHealth(), player.GetAttackDamage(), player.GetCooldown(), player.GetPlayerChoice(), enemyAttacks);

    // Run the story-mode fight: returns true if player (first arg) wins
    return game.StoryModeFight(player, enemy);
}
