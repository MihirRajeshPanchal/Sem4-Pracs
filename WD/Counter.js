import { useState } from 'react'

const Card = () => {
  const [count, setCount] = useState(0);

  return (
    <div>
      <style>
        {`
          #root {
            max-width: 1280px;
            margin: 0 auto;
            padding: 2rem;
            text-align: center;
          }

          .card {
            padding: 2em;
            gap: 2em;
          }

          button{
            margin: 20px;
            font-size: 25px;
            border-radius: 8px;
            border: 1px solid transparent;
            padding: 0.6em 1.2em;
            cursor: pointer;
            font-weight: 500;
          }
        `}
      </style>
      <h1>Counter app</h1>
      <h2>count is {count}</h2>
      <div className="card">
        <button className="inc" onClick={() => setCount((count) => count + 1)}>
          increment
        </button>
        <button className="dec" onClick={() => setCount((count) => count - 1)}>
          decrement
        </button>
        <button className="reset" onClick={() => setCount((count) => 0)}>
          reset
        </button>
      </div>
    </div>
  );
};

export default Card;
