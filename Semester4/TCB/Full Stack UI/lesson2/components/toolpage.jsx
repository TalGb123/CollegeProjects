import react from 'react';

const ToolPage = (props) => {
      const { name, price, link } = props;
      return (<>
            <h1>Tool Page</h1>
            <h2>{name}</h2>
            <p>{price}</p>
            <a href={link}>
                  <img src = "https://ae-pic-a1.aliexpress-media.com/kf/S634363253b70494b88f4fa452b86a3afF.jpg_960x960q75.jpg_.avif" alt = "ScrewDriver" 
                  width = "300" height = "300"/>
            </a>
      </>);
};

export default ToolPage;