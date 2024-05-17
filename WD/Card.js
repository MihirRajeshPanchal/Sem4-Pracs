import React from "react";
import image1 from "./asset/bg.jpg";
import image2 from "./asset/bg1.jpg";
import image3 from "./asset/bg2.jpg";

const Card = () => {
  return (
    <div>
      <style>
        {`
          * {
            box-sizing: border-box;
            font-family: sans-serif;
          }

          .container {
            display: flex;
            justify-content: center;
            flex-wrap: wrap;
            margin-top: 100px;
          }

          .card {
            width: 325px;
            border-radius: 10px;
            overflow: hidden;
            box-shadow: 0px 2px 4px rgb(223, 223, 223);
            margin: 20px;
          }

          .card img {
            width: 100%;
            height: auto;
          }

          .content {
            padding: 10px;
          }

          .content h2 {
            font-size: 28px;
            margin-bottom: 8px;
          }

          .content p {
            font-size: 15px;
            line-height: 1.3;
          }

          .btn {
            font-size: 35px;
            display: inline-block;
            padding-left: 20px;
            padding-right: 20px;
            padding-top: 5px;
            padding-bottom: 5px;
            background-color: #d1c7c7;
            text-decoration: none;
            border-radius: 4px;
            margin-top: 16px;
            color: green;
          }
        `}
      </style>
      <div className="container">
        <div className="card">
          <img src={image1} alt="Image 1" />
          <div className="content">
            <h2>Image 1</h2>
            <p>
              Lorem ipsum dolor sit, amet consectetur adipisicing elit. Nostrum,
              amet.
            </p>
            <a href="#" className="btn">
              Buy
            </a>
          </div>
        </div>

        <div className="card">
          <img src={image2} alt="Image 1" />
          <div className="content">
            <h2>Image 1</h2>
            <p>
              Lorem ipsum dolor sit, amet consectetur adipisicing elit. Nostrum,
              amet.
            </p>
            <a href="#" className="btn">
              Buy
            </a>
          </div>
        </div>

        <div className="card">
          <img src={image3} alt="Image 1" />
          <div className="content">
            <h2>Image 1</h2>
            <p>
              Lorem ipsum dolor sit, amet consectetur adipisicing elit. Nostrum,
              amet.
            </p>
            <a href="#" className="btn">
              Buy
            </a>
          </div>
        </div>
      </div>
    </div>
  );
};

export default Card;
