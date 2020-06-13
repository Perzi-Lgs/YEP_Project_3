import React from 'react';
import {Text} from 'react-native';

import GamePad from './GamePad';
import GameButton from './GameButton';

import {
  GameContainer,
  GameHalfContainer,
  GamePadPlusBorder,
  GamePadPlusMiddle,
  GamePadContainer,
  GamePadButton,
  EmptyGameButton,
} from './Style';

const Game = props => {
  const {
    onPressOut,
    handleOnDirUp,
    handleOnDirDown,
    handleOnDirLeft,
    handleOnDirRight,
    handleOnDirUpLong,
    handleOnDirDownLong,
    handleOnDirLeftLong,
    handleOnDirRightLong,
    pressA,
    pressB,
    isRight,
    isButtonRight,
    isButtonPlace,
  } = props;

  return (
    <GameContainer>
      {isRight ? (
        <GamePad
          onPressOut={onPressOut}
          handleOnDirUp={handleOnDirUp}
          handleOnDirDown={handleOnDirDown}
          handleOnDirLeft={handleOnDirLeft}
          handleOnDirRight={handleOnDirRight}
          handleOnDirUpLong={handleOnDirUpLong}
          handleOnDirDownLong={handleOnDirDownLong}
          handleOnDirLeftLong={handleOnDirLeftLong}
          handleOnDirRightLong={handleOnDirRightLong}
        />
      ) : (
        <GameButton
          isButtonRight={isButtonRight}
          isButtonPlace={isButtonPlace}
          pressA={pressA}
          pressB={pressB}
        />
      )}

      {isRight ? (
        <GameButton
          isButtonRight={isButtonRight}
          isButtonPlace={isButtonPlace}
          pressA={pressA}
          pressB={pressB}
        />
      ) : (
        <GamePad
          onPressOut={onPressOut}
          handleOnDirUp={handleOnDirUp}
          handleOnDirDown={handleOnDirDown}
          handleOnDirLeft={handleOnDirLeft}
          handleOnDirRight={handleOnDirRight}
          handleOnDirUpLong={handleOnDirUpLong}
          handleOnDirDownLong={handleOnDirDownLong}
          handleOnDirLeftLong={handleOnDirLeftLong}
          handleOnDirRightLong={handleOnDirRightLong}
        />
      )}
    </GameContainer>
  );
};

export default Game;
