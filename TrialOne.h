#pragma once

bool TrialOne() {
    cout << "You walk into the door and you find yourself in a large cave" << endl;
    cout << "In from of you is a empty void with 3 bridges leading to the other side" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Shadow Being: To get to the other side and the second trial you must choose the correct one" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Shadow Being: Choose wisely, for two of these bridges will fall when you try to walk on them." << endl;
    cout << "Shadow Being: You may still move onto the next trial if you fail although it may lead you to the end of your journey" << endl;
    cout << "What will you do?" << endl;
    cout << "1) Take the left bridge" << endl;
    cout << "2) Take the middle bridge" << endl;
    cout << "3) Take the right bridge" << endl;
    cout <<" 4) Look around the cave for clues" << endl;
    int choice;
    cin >> choice;
    if (choice == 4) {
        cout << "You walk around trying to find any clues about the bridges" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "The left bridge appears to have cracks all over it" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "The middle bridge appears to have been struck by lightning" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "The right bridge has pieces of it missing and skeletal remains" << endl;
        cout << "what will you do now?" << endl;
        cout << "1) Take the left bridge" << endl;
        cout << "2) Take the middle bridge" << endl;
        cout << "3) Take the right bridge" << endl;
        cin >> choice;
        if (choice == 1) {
        cout << "You walk onto the left bridge" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "As you reach the middle of the bridge it starts to crack and fall apart" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "You try to run back but it's too late, you fall into the void below" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "You wake up at the entrance of a door, having failed the trial" << endl;
        return false;
    }
    if (choice == 2) {
        cout << "You walk onto the middle bridge" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "As you reach the middle of the bridge it starts to sizzle and smoke" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "Suddenly a bolt of lightning strikes, you brace for impact but the lightning is absorbed into your body" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "You walk past the bridge and enter the second trial" << endl;
        return true;
    }
    if (choice == 3) {
        cout << "You walk onto the right bridge" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "You take 3 steps onto the bridge and it immediately crumbles you fall into the void.." << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "You wake up at the entrance of a different door, failing the first trial" << endl;
        return false;
    }
    }
    else if (choice == 1) {
        cout << "You walk onto the left bridge" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "As you reach the middle of the bridge it starts to crack and fall apart" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "You try to run back but it's too late, you fall into the void below" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "You wake up at the entrance of a door, having failed the trial" << endl;
        return false;
    }
    else if (choice == 2) {
        cout << "You walk onto the middle bridge" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "As you reach the middle of the bridge it starts to sizzle and smoke" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "Suddenly a bolt of lightning strikes, you brace for impact but the lightning is absorbed into your body" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "You walk past the bridge and enter the second trial" << endl;
        return true;
    }
    else if (choice == 3) {
        cout << "You walk onto the right bridge" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "You take 3 steps onto the bridge and it immediately crumbles you fall into the void.." << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "You wake up at the entrance of a different door, failing the first trial" << endl;
        return false;
    }

}