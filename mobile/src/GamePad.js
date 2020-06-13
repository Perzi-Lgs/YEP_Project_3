import React from 'react';
import Icon from 'react-native-vector-icons/FontAwesome';

import {
  GameHalfContainer,
  GamePadPlusBorder,
  GamePadPlusMiddle,
  GamePadContainer,
  GamePadButton,
  EmptyGameButton,
} from './Style';

const GamePad = props => {
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
  } = props;

  return (
    <GameHalfContainer>
      <GamePadContainer>
        <GamePadPlusBorder>
          <GamePadButton
            onPressIn={handleOnDirUp}
            onLongPress={handleOnDirUpLong}
            onPressOut={onPressOut}>
            <Icon name="chevron-up" size={50} />
          </GamePadButton>
        </GamePadPlusBorder>

        <GamePadPlusMiddle>
          <GamePadButton
            onPressIn={handleOnDirLeft}
            onLongPress={handleOnDirLeftLong}
            onPressOut={onPressOut}>
            <Icon name="chevron-left" size={50} />
          </GamePadButton>

          <EmptyGameButton />

          <GamePadButton
            onPressIn={handleOnDirRight}
            onLongPress={handleOnDirRightLong}
            onPressOut={onPressOut}>
            <Icon name="chevron-right" size={50} />
          </GamePadButton>
        </GamePadPlusMiddle>

        <GamePadPlusBorder>
          <GamePadButton
            onPressIn={handleOnDirDown}
            onLongPress={handleOnDirDownLong}
            onPressOut={onPressOut}>
            <Icon name="chevron-down" size={50} />
          </GamePadButton>
        </GamePadPlusBorder>
      </GamePadContainer>
    </GameHalfContainer>
  );
};

export default GamePad;
