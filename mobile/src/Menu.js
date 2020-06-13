import React from 'react';
import {Text} from 'react-native';
import {MenuContainer, SelectButton} from './Style';

const Menu = props => {
  const {selectFct, startFct} = props;

  return (
    <MenuContainer>
      <SelectButton onPressIn={selectFct}>
        <Text>SELECT</Text>
      </SelectButton>

      <SelectButton onPressIn={startFct}>
        <Text>START</Text>
      </SelectButton>
    </MenuContainer>
  );
};

export default Menu;
