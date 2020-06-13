import React from 'react';
import {Text} from 'react-native';

import {
  GameHalfContainer,
  ButtonsRow,
  ButtonContainer,
  GameButtonView,
} from './Style';

const GameButton = props => {
  const {pressA, pressB, isButtonRight, isButtonPlace} = props;

  const secondRow = () => {
    return (
      <ButtonsRow>
        {isButtonRight ? (
          <ButtonContainer>
            <GameButtonView onPress={pressB}>
              <Text>B</Text>
            </GameButtonView>
          </ButtonContainer>
        ) : (
          <GameHalfContainer />
        )}

        {isButtonRight ? (
          <GameHalfContainer />
        ) : (
          <ButtonContainer>
            <GameButtonView onPress={pressB}>
              <Text>B</Text>
            </GameButtonView>
          </ButtonContainer>
        )}
      </ButtonsRow>
    );
  };

  const firstRow = () => {
    return (
      <ButtonsRow>
        {isButtonRight ? (
          <GameHalfContainer />
        ) : (
          <ButtonContainer>
            <GameButtonView onPress={pressA}>
              <Text>A</Text>
            </GameButtonView>
          </ButtonContainer>
        )}
        {isButtonRight ? (
          <ButtonContainer>
            <GameButtonView onPress={pressA}>
              <Text>A</Text>
            </GameButtonView>
          </ButtonContainer>
        ) : (
          <GameHalfContainer />
        )}
      </ButtonsRow>
    );
  };

  return (
    <GameHalfContainer>
      {isButtonPlace ? firstRow() : secondRow()}
      {isButtonPlace ? secondRow() : firstRow()}
    </GameHalfContainer>
  );
};

export default GameButton;
