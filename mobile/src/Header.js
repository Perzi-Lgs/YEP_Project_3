import React, {useEffect, useState} from 'react';
import {HeaderContainer, ConnectionContainer, ButtonConnect} from './Style';

import {SettingIcon, SettingButton, ScoreText} from './Style';

const Header = props => {
  const [score, setScore] = useState(0);
  const {setModal, isConnect, setConnectionModal, setConnection} = props;

  useEffect(() => {
    //Get Score
    setScore(0);
  }, [score]);

  return (
    <HeaderContainer>
      <ScoreText>{`SCORE: ${score}`}</ScoreText>

      <ConnectionContainer
        onPress={() =>
          isConnect ? setConnectionModal(true) : setConnection(false)
      }>
        <ScoreText>{`${isConnect ? 'Connected' : 'Deconnected'}`}</ScoreText>
        <ButtonConnect isConnect={isConnect} />
      </ConnectionContainer>

      <SettingButton onPress={() => setModal(true)}>
        <SettingIcon name={'settings'} color={'#FFFFFF'} size={40} />
      </SettingButton>
    </HeaderContainer>
  );
};

export default Header;
